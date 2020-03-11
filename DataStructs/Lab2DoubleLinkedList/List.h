#pragma once
#include "StructList.h"

List* CreateList();
void AddNode(List* list, int data);
void DeleteNode(List* list, size_t index);
void InsertNode(List* list, size_t index, int data);
void BubbleSort(List* list);
void LinearSearch(const List* list, int value);
void DeleteList(const List* list);
Node* GetNode(const List* list, const size_t index);
void SwapNode(List* list, Node* current);