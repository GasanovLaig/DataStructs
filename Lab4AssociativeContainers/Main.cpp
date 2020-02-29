#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");

	while (true)
	{
		system("cls");
		PrintMainTextMenu();

		cout << "\nВведите номер команды: ";
		CommandMenu command = GetValue(CommandMenu::HashTable,
			CommandMenu::Exit, IsRange);

		switch (command)
		{
			case CommandMenu::HashTable:
			{
				PrintMenu<HashTable>();
				break;
			}
			case CommandMenu::Dictionary:
			{
				PrintMenu<Dictionary>();
				break;
			}
			case CommandMenu::Exit:
			{
				return 0;
			}
		}
	}
}