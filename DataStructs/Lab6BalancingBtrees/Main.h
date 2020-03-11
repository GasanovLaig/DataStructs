#pragma once
#include "AvlTree.h"
#include "RedBlackTree.h"

#include <iostream>
#include "../Common/GetValue.h"
#include "../Common/GetRandomValue.h"
#include "MenuCommands.h"
#include "Testing.h"
using namespace std;
using DataType = int;

void PrintDataStructTextMenu();

template <typename T>
void PrintMenu(T& tree)
{
	while (true)
	{
		system("cls");
		cout << "Высота дерева: " << tree.GetHeight() << "\n\n";
		tree.Print();
		PrintDataStructTextMenu();
		cout << "\nВведите номер команды: ";
		Command command = GetValue(Command::AddRandomValues,
			Command::Exit, IsRange);

		switch (command)
		{
			case Command::AddRandomValues:
			{
				cout << "Введите количество элементов: ";
				size_t count = GetValue<size_t>();
				for (size_t i = 0; i < count; ++i)
				{
					tree.Add(GetRandomValue<DataType>());
				}
				break;
			}
			case Command::AddValue:
			{
				cout << "Введите ключ: ";
				DataType key = GetValue<DataType>();
				tree.Add(key);
				break;
			}
			case Command::RemoveValue:
			{
				cout << "Введите ключ: ";
				DataType key = GetValue<DataType>();
				tree.Remove(key);
				break;
			}
			case Command::FindValue:
			{
				cout << "Введите ключ: ";
				DataType key = GetValue<DataType>();
				bool isFinded = tree.Find(key);
				cout << ((isFinded) ?
					"\nКлюч найден!\n" :
					"\nКлюч не найден!\n");
				system("pause");
				break;
			}
			case Command::Exit:
			{
				return;
			}
		}
	}
}

void PrintMainTextMenu()
{
	cout << "\n\n\t 0 АВЛ-дерево.\n" <<
		"\t 1 Красно-чёрное дерево.\n" <<
		"\t 2 Тестирование вставки и удаления деревьев.\n" <<
		"\t 3 Выход из программы.\n";
}

void PrintDataStructTextMenu()
{
	cout << "\n\n\t 0 Добавить n рандомных ключей.\n" <<
		"\t 1 Добавить ключ.\n" <<
		"\t 2 Удалить ключ.\n" <<
		"\t 3 Поиск по ключу.\n" <<
		"\t 4 Выход в главное меню.\n";
}