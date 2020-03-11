#pragma once

struct DynamicArray
{
	int* Array;
	size_t Size;
	size_t MaxSize;
	bool IsSorted;
};

DynamicArray* CreateDynamicArray();
void ResizeArray(DynamicArray* container);
void InsertElement(DynamicArray* container, size_t index, int data);
void DeleteElement(DynamicArray* container, size_t index);
void LinearSearch(const DynamicArray* container, int value);
void InsertionSort(DynamicArray* container);
void BinarySearch(const DynamicArray* container, int value);
void DeleteDynamicArray(const DynamicArray* container);

void PrintArray(const DynamicArray* container);
void CopyArray(const DynamicArray* container, int* copyArray);
void PrintMenu();