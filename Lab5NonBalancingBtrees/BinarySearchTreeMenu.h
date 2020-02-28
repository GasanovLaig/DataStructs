#pragma once
#include "Treap.h"
#include <iostream>
#include "MenuCommands.h"
#include "../myLib/GetRandomValue.h"
#include "../myLib/GetValue.h"
using namespace std;

void PrintBinarySearchTreeTextMenu();

template <typename T>
void PrintBinarySearchTreeMenu()
{
	BinaryTree<T> tree;

	while (true)
	{
		system("cls");
		tree.Print();
		PrintBinarySearchTreeTextMenu();

		cout << "\nВведите команду: ";
		BstCommand command = GetValue(BstCommand::AddValue,
			BstCommand::Exit, IsRange);

		try
		{
			switch (command)
			{
				case BstCommand::AddValue:
				{
					cout << "Введите ключ: ";
					tree.Add(GetValue<T>());
					break;
				}
				case BstCommand::AddRandomValues:
				{
					cout << "Введите количество элементов: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						tree.Add(GetRandomValue<T>());
					}
					break;
				}
				case BstCommand::RemoveValue:
				{
					cout << "Введите ключ: ";
					tree.Remove(GetValue<T>());
					break;
				}
				case BstCommand::FindValue:
				{
					cout << "Введите ключ: ";
					const BstNode<T>* result = tree.Find(GetValue<T>());
					if (result == nullptr)
					{
						 std::exception("Ключ не найден!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FindMin:
				{
					cout << "Введите ключ: ";
					const BstNode<T>* result = tree.FindMin();
					if (result == nullptr)
					{
						std::exception("Минимальный ключ не найден!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FindMax:
				{
					cout << "Введите ключ: ";
					const BstNode<T>* result = tree.FindMax();
					if (result == nullptr)
					{
						std::exception("Максимальный ключ не найден!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::Exit:
				{
					return;
				}
			}
		}
		catch (const bad_alloc&)
		{
			cerr << "Ошибка выделения памяти!\n";
			system("pause");
		}
		catch (const exception& exception)
		{
			cerr << exception.what() << '\n';
			system("pause");
		}
	}
}

void PrintBinarySearchTreeTextMenu()
{
	cout << "\n\n\t 0 Добавить ключ.\n" <<
		"\t 1 Добавить n рандомных ключей.\n" <<
		"\t 2 Удалить ключ.\n" <<
		"\t 3 Поиск по ключу.\n" <<
		"\t 4 Поиск минимального ключа.\n" <<
		"\t 5 Поиск максимальног ключа.\n" <<
		"\t 6 Выход в главное меню.\n";
}