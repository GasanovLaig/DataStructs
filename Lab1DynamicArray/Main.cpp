#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	DynamicArray* container = CreateDynamicArray();

	while (true)
	{
		system("cls");
		cout << " Массив (" << container->Size << " элемента)\n";
		PrintArray(container);
		cout << '\n';
		PrintMenu();

		cout << "\nВведите номер команды: ";
		Command command = GetValue<Command>(Command::DeleteValue,
			Command::Exit,	IsRange);
		switch (command)
		{
			case Command::DeleteValue:
			{
				cout << "Введите индекс элемента: ";
				DeleteElement(container,
					GetValue<size_t>(0, (container->Size - 1), IsRange));
				break;
			}
			case Command::InsertInBegin:
			{
				cout << "Введите значение элемента: ";
				InsertElement(container, 0, GetValue<int>());
				break;
			}
			case Command::InsertInEnd:
			{
				cout << "Введите значение элемента: ";
				InsertElement(container, container->Size, GetValue<int>());
				break;
			}
			case Command::InsertAfter:
			{
				cout << "Введите индекс элемента: ";
				InsertElement(container,
					(GetValue<size_t>(0, (container->Size - 1), IsRange) + 1),
					GetValue<int>());
				break;
			}
			case Command::Sort:
			{
				InsertionSort(container);
				break;
			}
			case Command::LinearSearch:
			{
				cout << "Введите элемент поиска: ";
				LinearSearch(container, GetValue<int>());
				cout << '\n';
				system("pause");
				break;
			}
			case Command::BinarySearch:
			{
				cout << "Введите элемент поиска: ";
				BinarySearch(container, GetValue<int>());
				cout << '\n';
				system("pause");
				break;
			}
			case Command::Exit:
			{
				DeleteDynamicArray(container);
				return 0;
			}
		}
	}
}