#include "globalDefs.h"

int main()
{
	srand((unsigned int)time(NULL));

	node *head = NULL;
	float average;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("COLOR 0B");

	head = readListFromBinaryFile(head);

	while (1)
	{
		system("cls");
		switch (menu())
		{
		case '1':
			system("cls");
			switch (subMenuAdd())
			{
			case '1': 
				head = addToHead(head);
				_getch();
				break;
			case '2':
				head = addToTail(head);
				_getch();
				break;
			case '3':
				head = insertToList(head);
				_getch();
				break;
			case '0':
				break;
			}
			break;
		case '2':
			system("cls");
			switch (subMenuSearch())
			{
			case '1':
				searchID(head);
				_getch();
				break;
			case '0':
				break;
			}
			break;
		case '3': 
			system("cls");
			switch (subMenuDelete())
			{
			case '1':
				head = deleteEntry(head);
				_getch();
				break;
			case '2':
				destroyList(head);
				_getch();
				break;
			case '0':
				break;
			}
			break;
		case '4':
			system("cls");
			switch (subMenuPrint())
			{
			case '1':
				printList(head);
				_getch();
				break;
			case '2':
				average = getAverage(head);
				printAvgFromFile(head, average);
				_getch();
				break;
			case '0':
				break;
			}
			break;
		case '0':
			exportToBinaryFile(head);
			memoryCleanup(head);
			return 0;
		}
	}

	exportToBinaryFile(head);
	memoryCleanup(head);
}