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

		cout << "\nТтхфшђх ъюьрэфѓ: ";
		BstCommand command = GetValue(BstCommand::AddValue,
			BstCommand::Exit, IsRange);

		try
		{
			switch (command)
			{
				case BstCommand::AddValue:
				{
					cout << "Ттхфшђх ъыўї: ";
					tree.Add(GetValue<T>());
					break;
				}
				case BstCommand::AddRandomValues:
				{
					cout << "Ттхфшђх ъюышїхёђтю §ыхьхэђют: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						tree.Add(GetRandomValue<T>());
					}
					break;
				}
				case BstCommand::RemoveValue:
				{
					cout << "Ттхфшђх ъыўї: ";
					tree.Remove(GetValue<T>());
					break;
				}
				case BstCommand::FindValue:
				{
					cout << "Ттхфшђх ъыўї: ";
					const BstNode<T>* result = tree.Find(GetValue<T>());
					if (result == nullptr)
					{
						 std::exception("Ъыўї эх эрщфхэ!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FindMin:
				{
					cout << "Ттхфшђх ъыўї: ";
					const BstNode<T>* result = tree.FindMin();
					if (result == nullptr)
					{
						std::exception("Ьшэшьрыќэћщ ъыўї эх эрщфхэ!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FindMax:
				{
					cout << "Ттхфшђх ъыўї: ";
					const BstNode<T>* result = tree.FindMax();
					if (result == nullptr)
					{
						std::exception("Ьръёшьрыќэћщ ъыўї эх эрщфхэ!");
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
			cerr << "Юјшсър тћфхыхэшџ ярьџђш!\n";
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
	cout << "\n\n\t 0 Фюсртшђќ ъыўї.\n" <<
		"\t 1 Фюсртшђќ n №рэфюьэћѕ ъыўїхщ.\n" <<
		"\t 2 гфрышђќ ъыўї.\n" <<
		"\t 3 Яюшёъ яю ъыўїѓ.\n" <<
		"\t 4 Яюшёъ ьшэшьрыќэюую ъыўїр.\n" <<
		"\t 5 Яюшёъ ьръёшьрыќэюу ъыўїр.\n" <<
		"\t 6 Тћѕюф т уыртэюх ьхэў.\n";
}