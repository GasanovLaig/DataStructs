#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand(static_cast<size_t>(time(nullptr)));
	using KeyType = int;

	while (true)
	{
		system("cls");
		PrintTextMainMenu();

		cout << "\n¬ведите команду: ";
		CommandMenu command = GetValue(CommandMenu::BinarySearchTree,
			CommandMenu::Exit, IsRange);

		switch (command)
		{
			case CommandMenu::BinarySearchTree:
			{
				PrintBinarySearchTreeMenu<KeyType>();
				break;
			}
			case CommandMenu::Treap:
			{
				PrintTreapMenu<KeyType>();
				break;
			}
			case CommandMenu::Exit:
			{
				return 0;
			}
		}
	}
}