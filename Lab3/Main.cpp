#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	using DataType = int;
	
	while (true)
	{
		system("cls");
		PrintMainTextMenu();

		cout << "������� ����� �������: ";
		Command command = GetValue(Command::Stack, Command::Exit,
			IsRange);

		switch (command)
		{
			case Command::Stack:
			{
				string menuName("����");

				using Stack = Stack<DataType>;
				Stack stack;
				Print<Stack, DataType>(stack, &Stack::Push, &Stack::Pop,
					&Stack::Print, menuName);
				break;
			}
			case Command::DoubleStackQueue:
			{
				string menuName("������� �� ������ ���� ������");

				using Queue = DoubleStackQueue<DataType>;
				Queue queue;
				Print<Queue, DataType>(queue, &Queue::Enqueue, &Queue::Dequeue,
					&Queue::Print, menuName);
				break;
			}
			case Command::RingBuffer:
			{
				string menuName("��������� �����");

				using Ring = RingBuffer<DataType>;
				cout << "������� ������ ������: ";
				size_t startingBufferSize = GetValue<size_t>();
				Ring ring(startingBufferSize);

				Print<Ring, DataType>(ring, &Ring::Enqueue, &Ring::Dequeue,
					&Ring::Print, menuName);
				break;
			}
			case Command::Exit:
			{
				return 0;
			}
		}
	}
}