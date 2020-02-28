#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		system("cls");
		PrintMainTextMenu();
		cout << "\n������� ����� �������: ";
		CommandMenu command = GetValue(CommandMenu::AvlTree,
			CommandMenu::Exit, IsRange);

		switch (command)
		{
			case CommandMenu::AvlTree:
			{
				AvlTree<DataType> tree;
				PrintMenu(tree);
				break;
			}
			case CommandMenu::RedBlackTree:
			{
				RedBlackTree<DataType> tree;
				PrintMenu(tree);
				break;
			}
			case CommandMenu::Testing:
			{
				cout << "������� ���������� ���������: ";
				Testing(GetValue<size_t>());
				system("pause");
				break;
			}
			case CommandMenu::Exit:
			{
				return 0;
			}
		}
	}
}