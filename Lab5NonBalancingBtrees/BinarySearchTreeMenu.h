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

		cout << "\n������� �������: ";
		BstCommand command = GetValue(BstCommand::AddValue,
			BstCommand::Exit, IsRange);

		try
		{
			switch (command)
			{
				case BstCommand::AddValue:
				{
					cout << "������� ����: ";
					tree.Add(GetValue<T>());
					break;
				}
				case BstCommand::AddRandomValues:
				{
					cout << "������� ���������� ���������: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						tree.Add(GetRandomValue<T>());
					}
					break;
				}
				case BstCommand::RemoveValue:
				{
					cout << "������� ����: ";
					tree.Remove(GetValue<T>());
					break;
				}
				case BstCommand::FindValue:
				{
					cout << "������� ����: ";
					const BstNode<T>* result = tree.Find(GetValue<T>());
					if (result == nullptr)
					{
						 std::exception("���� �� ������!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FindMin:
				{
					cout << "������� ����: ";
					const BstNode<T>* result = tree.FindMin();
					if (result == nullptr)
					{
						std::exception("����������� ���� �� ������!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FindMax:
				{
					cout << "������� ����: ";
					const BstNode<T>* result = tree.FindMax();
					if (result == nullptr)
					{
						std::exception("������������ ���� �� ������!");
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
			cerr << "������ ��������� ������!\n";
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
	cout << "\n\n\t 0 �������� ����.\n" <<
		"\t 1 �������� n ��������� ������.\n" <<
		"\t 2 ������� ����.\n" <<
		"\t 3 ����� �� �����.\n" <<
		"\t 4 ����� ������������ �����.\n" <<
		"\t 5 ����� ������������ �����.\n" <<
		"\t 6 ����� � ������� ����.\n";
}