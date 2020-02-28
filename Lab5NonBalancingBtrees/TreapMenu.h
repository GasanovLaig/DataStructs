#pragma once
#include "Treap.h"
#include "MenuCommands.h"
#include "../myLib/GetValue.h"
#include "../myLib/GetRandomValue.h"
#include "TreapTesting.h"
using namespace std;

void PrintTreapTextMenu();

template <typename T>
void PrintTreapMenu()
{
	Treap<T> treap;

	while (true)
	{
		std::system("cls");
		treap.Print();
		PrintTreapTextMenu();

		cout << "\n������� �������: ";
		TreapCommand command = GetValue(TreapCommand::AddRandomValues,
			TreapCommand::Exit, IsRange);

		try
		{
			switch (command)
			{
				case TreapCommand::AddRandomValues:
				{
					cout << "������� ���������� ���������: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						treap.AddNonOptimized(GetRandomValue<T>());
					}
					break;
				}
				case TreapCommand::AddValueNonOptimized:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.AddNonOptimized(key);
					break;
				}
				case TreapCommand::AddValueOptimized:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.AddOptimized(key);
					break;
				}
				case TreapCommand::RemoveValueNonOptimized:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.RemoveNonOptimized(key);
					break;
				}
				case TreapCommand::RemoveValueOptimized:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.RemoveOptimized(key);
					break;
				}
				case TreapCommand::FindValue:
				{
					cout << "������� ����: ";
					cout << "\n���������: " << (treap.Find(GetValue<T>())) ?
						"���� ������!" :
						"���� �� ������!";
					system("pause");
					break;
				}
				case TreapCommand::Testing:
				{
					cout << "���������� ���������: ";
					Testing(GetValue<size_t>());
					system("pause");
					break;
				}
				case TreapCommand::Exit:
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

void PrintTreapTextMenu()
{
	cout << "\n\n\t 0 �������� n ��������� ������.\n" <<
		"\t 1 �������� ����(�� ����������������).\n" <<
		"\t 2 �������� ����(����������������).\n" <<
		"\t 3 ������� ����(�� ����������������).\n" <<
		"\t 4 ������� ����(����������������).\n" <<
		"\t 5 ����� �� �����.\n" <<
		"\t 6 ������������� ������� � ��������.\n" <<
		"\t 7 ����� � ������� ����.\n";
}