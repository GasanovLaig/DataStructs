#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	List* list = CreateList();

	while (true)
	{
		system("cls");
		cout << "Количество элементов в списке: " << list->Size << '\n';
		PrintList(list);
		PrintMenu();

		size_t lastElementIndex = list->Size - 1;
		try
		{
			cout << "\nВведите номер команды: ";
			Command command = GetValue(Command::AddValue,
				Command::Exit, IsRange);
			switch (command)
			{
				case Command::AddValue:
				{
					std::cout << "Введите значение: ";
					AddNode(list, GetValue<int>());
					break; 
				}
				case Command::DeleteValue:
				{
					std::cout << "Введите индекс элемента: ";
					DeleteNode(list, GetValue<size_t>(0, list->Size - 1,
						IsRange));
					break;
				}
				case Command::InsertInBegin:
				{
					std::cout << "Введите значение: ";
					InsertNode(list, 0, GetValue<int>());
					break;
				}
				case Command::InsertInEnd:
				{
					InsertNode(list, lastElementIndex, GetValue<int>());
					break;
				}
				case Command::InsertAfter:
				{
					IsEmpty(list);
					cout << "Введите индекс элемента: ";
					InsertNode(list,
						GetValue<size_t>(0, lastElementIndex, IsRange) + 1,
						GetValue<int>());
					break;
				}
				case Command::InsertBefore:
				{
					IsEmpty(list);
					cout << "Введите индекс элемента: ";
					InsertNode(list,
						GetValue<size_t>(0, lastElementIndex, IsRange),
						GetValue<int>());
					break;
				}
				case Command::Sort:
				{
					BubbleSort(list);
					break;
				}
				case Command::LinearSearch:
				{
					cout << "Введите значение поиска: ";
					LinearSearch(list, GetValue<int>());
					system("pause");
					break;
				}
				case Command::Exit:
				{
					DeleteList(list);
					return 0;
				}
			}
		}
		catch (const exception& exception)
		{
			cerr << exception.what() << '\n';
			system("pause");
		}
	}
}