#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	DynamicArray* container = CreateDynamicArray();

	while (true)
	{
		system("cls");
		cout << " ������ (" << container->Size << " ��������)\n";
		PrintArray(container);
		cout << '\n';
		PrintMenu();

		cout << "\n������� ����� �������: ";
		Command command = GetValue<Command>(Command::DeleteValue,
			Command::Exit,	IsRange);
		switch (command)
		{
			case Command::DeleteValue:
			{
				cout << "������� ������ ��������: ";
				DeleteElement(container,
					GetValue<size_t>(0, (container->Size - 1), IsRange));
				break;
			}
			case Command::InsertInBegin:
			{
				cout << "������� �������� ��������: ";
				InsertElement(container, 0, GetValue<int>());
				break;
			}
			case Command::InsertInEnd:
			{
				cout << "������� �������� ��������: ";
				InsertElement(container, container->Size, GetValue<int>());
				break;
			}
			case Command::InsertAfter:
			{
				cout << "������� ������ ��������: ";
				InsertElement(container,
					(GetValue<size_t>(0, (container->Size - 1), IsRange) + 1),
					GetValue<int>());
				break;
			}
			case Command::Sort:
			{
				InsertionSort(container);
				break;
			}
			case Command::LinearSearch:
			{
				cout << "������� ������� ������: ";
				LinearSearch(container, GetValue<int>());
				cout << '\n';
				system("pause");
				break;
			}
			case Command::BinarySearch:
			{
				cout << "������� ������� ������: ";
				BinarySearch(container, GetValue<int>());
				cout << '\n';
				system("pause");
				break;
			}
			case Command::Exit:
			{
				DeleteDynamicArray(container);
				return 0;
			}
		}
	}
}