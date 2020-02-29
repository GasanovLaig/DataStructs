#pragma once
#include "Stack.h"
#include "DoubleStackQueue.h"
#include "RingBuffer.h"

#include "MenuCommands.h"
#include "../myLib/GetValue.h"
using namespace std;

void PrintTextMenu();

template <typename T, typename DATA_TYPE>
void Print(T& abstractStructData, void (T::*SetData)(DATA_TYPE data),
	DATA_TYPE (T::*GetData)(), void (T::*Print)(), const string& menuName)
{
	while (true)
	{
		system("cls");
		cout << menuName << '\n';
		PrintTextMenu();
		(abstractStructData.*Print)();

		try
		{
			cout << "\nВведите номер команды: ";
			CommandAsd command = GetValue(CommandAsd::Input,
				CommandAsd::Exit, IsRange);

			switch (command)
			{
				case CommandAsd::Input:
				{
					cout << "Введите значение: ";
					DATA_TYPE data = GetValue<DATA_TYPE>();
					(abstractStructData.*SetData)(data);
					break;
				}
				case CommandAsd::Output:
				{
					(abstractStructData.*GetData)();
					break;
				}
				case CommandAsd::Exit:
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

void PrintTextMenu()
{
	cout << "\n\t0 Добавить элемент.\n" <<
		"\t1 Извлечь элемент.\n" <<
		"\t2 Выход.\n\n";
}

void PrintMainTextMenu()
{
	cout << "Главное меню\n\n\t0 Создать стек.\n" <<
		"\t1 Создать очередь на основе двух стеков.\n" <<
		"\t2 Создать кольцевой буфер.\n" <<
		"\t3 Выход из программы.\n\n";
}