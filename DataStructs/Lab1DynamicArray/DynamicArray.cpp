#include "DynamicArray.h"
#include <iostream>
using namespace std;

inline short GetStartinSize() { return 3; }
inline float GetGrowthFactor() { return 1.5; }

DynamicArray* CreateDynamicArray()
{
	DynamicArray* container = new DynamicArray;
	container->MaxSize = static_cast<size_t>(GetGrowthFactor() *
		GetStartinSize());
	container->Array = new int[container->MaxSize];

	container->Size = 0;
	container->IsSorted = false;
	return container;
}

void ResizeArray(DynamicArray* container)
{
	++container->Size;
	if (container->Size > container->MaxSize)
	{
		container->MaxSize = static_cast<size_t>(GetGrowthFactor() * container->Size);
		int *newArray = new int[container->MaxSize];
		CopyArray(container, newArray);

		delete[] container->Array;
		container->Array = newArray;
	}
}

void InsertElement(DynamicArray* container, size_t index, int data)
{
	ResizeArray(container);
	for (size_t i = container->Size - 1; i > index; --i)
	{
		container->Array[i] = container->Array[i - 1];
	}

	container->Array[index] = data;
	container->IsSorted = false;
}

void DeleteElement(DynamicArray* container, size_t index)
{
	if (container->Size > 0)
	{
		for (; index < container->Size; ++index)
		{
			container->Array[index] = container->Array[index + 1];
		}
		--container->Size;
	}
	else
	{
		cout << "Массив пуст."
			<< endl;
		system("pause");
	}
}

void LinearSearch(const DynamicArray* container, int value)
{
	for (size_t i = 0; i < container->Size; ++i)
	{
		if (value == container->Array[i])
		{
			cout << " container[" << i << "] = "
				<< container->Array[i] << ", ";
		}
	}
}

void InsertionSort(DynamicArray* container)
{
	if (!container->IsSorted)
	{
		int temp;
		for (size_t i = 1; i < container->Size; ++i)
		{
			for (size_t j = i; j > 0; --j)
			{
				if (container->Array[j] < container->Array[j - 1])
				{
					temp = container->Array[i];
					container->Array[i] = container->Array[j - 1];
					container->Array[j - 1] = temp;
				}
			}
		}

		container->IsSorted = true;
	}
	else
	{
		cout << "Массив отсортирован!" << endl;
		system("pause");
	}
}

void BinarySearch(const DynamicArray* container, int value)
{
	size_t left = 0;
	size_t right = container->Size - 1;
	size_t mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (container->Array[mid] == value)
		{
			cout << "container[" << mid << "] = "
				<< container->Array[mid] << ", ";
		}

		(value < container->Array[mid]) ?
			right = mid - 1 :
			left = mid + 1;
	}
}

void DeleteDynamicArray(const DynamicArray* container)
{
	if (container != nullptr && container->Array != nullptr)
	{
		delete[] container->Array;
		delete container;
	}
}

void PrintArray(const DynamicArray* container)
{
	for (size_t i = 0; i < container->Size; ++i)
	{
		cout << ' ' << container->Array[i];
	}
}

void CopyArray(const DynamicArray* container, int* copyArray)
{
	for (size_t i = 0; i < container->Size; ++i)
	{
		copyArray[i] = container->Array[i];
	}
}

void PrintMenu()
{
	cout << "\t0 Удаление элемента из массива.\n" <<
		"\t1 Вставка элемента в начало массива.\n" <<
		"\t2 Вставка элемента в конец массива.\n" <<
		"\t3 Вставка после определенного элемента.\n" <<
		"\t4 Сортировка массива.\n" <<
		"\t5 Линеный поиск элемента в массиве.\n" <<
		"\t6 Бинарный поиск элемента в массиве.\n" <<
		"\t7 Выход из программы." << endl;
}