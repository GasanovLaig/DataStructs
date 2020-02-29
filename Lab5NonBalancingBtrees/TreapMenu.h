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

		cout << "\nТтхфшђх ъюьрэфѓ: ";
		TreapCommand command = GetValue(TreapCommand::AddRandomValues,
			TreapCommand::Exit, IsRange);

		try
		{
			switch (command)
			{
				case TreapCommand::AddRandomValues:
				{
					cout << "Ттхфшђх ъюышїхёђтю §ыхьхэђют: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						treap.AddNonOptimized(GetRandomValue<T>());
					}
					break;
				}
				case TreapCommand::AddValueNonOptimized:
				{
					cout << "Ттхфшђх ъыўї: ";
					T key = GetValue<T>();
					treap.AddNonOptimized(key);
					break;
				}
				case TreapCommand::AddValueOptimized:
				{
					cout << "Ттхфшђх ъыўї: ";
					T key = GetValue<T>();
					treap.AddOptimized(key);
					break;
				}
				case TreapCommand::RemoveValueNonOptimized:
				{
					cout << "Ттхфшђх ъыўї: ";
					T key = GetValue<T>();
					treap.RemoveNonOptimized(key);
					break;
				}
				case TreapCommand::RemoveValueOptimized:
				{
					cout << "Ттхфшђх ъыўї: ";
					T key = GetValue<T>();
					treap.RemoveOptimized(key);
					break;
				}
				case TreapCommand::FindValue:
				{
					cout << "Ттхфшђх ъыўї: ";
					cout << "\nахчѓыќђрђ: " << (treap.Find(GetValue<T>())) ?
						"ъыўї эрщфхэ!" :
						"ъыўї эх эрщфхэ!";
					system("pause");
					break;
				}
				case TreapCommand::Testing:
				{
					cout << "Ъюышїхёђтю §ыхьхэђют: ";
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

void PrintTreapTextMenu()
{
	cout << "\n\n\t 0 Фюсртшђќ n №рэфюьэћѕ ъыўїхщ.\n" <<
		"\t 1 Фюсртшђќ ъыўї(эх юяђшьшчш№ютрээћщ).\n" <<
		"\t 2 Фюсртшђќ ъыўї(юяђшьшчш№ютрээћщ).\n" <<
		"\t 3 гфрышђќ ъыўї(эх юяђшьшчш№ютрээћщ).\n" <<
		"\t 4 гфрышђќ ъыўї(юяђшьшчш№ютрээћщ).\n" <<
		"\t 5 Яюшёъ яю ъыўїѓ.\n" <<
		"\t 6 вхёђш№ютртэшх тёђртъш ш ѓфрыхэшџ.\n" <<
		"\t 7 Тћѕюф т уыртэюх ьхэў.\n";
}