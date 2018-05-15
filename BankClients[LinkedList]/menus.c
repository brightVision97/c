#include "globalDefs.h"

char menu()
{
	char ch;

	printf("|------------------СВЪРЗАН СПИСЪК-КЛИЕНТИ НА БАНКА------------------|\n");
	printf("| 1. Добавяне на нов клиент                                         |\n");
	printf("| 2. Търсене на клиент                                              |\n");
	printf("| 3. Изтриване                                                      |\n");
	printf("| 4. Извеждане на екрана                                            |\n");
	printf("| 0. Изход и запис на данните                                       |\n");
	printf("|-------------------------------------------------------------------|\n");

	do
	{
		fflush(stdin);
		printf("\nИзбор: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '4');

	return ch;
}

char subMenuPrint()
{
	char ch;

	printf("\n1. Извеждане на целия списък");
	printf("\n2. Извеждане по зададен критерий");
	printf("\n0. Назад");

	do
	{
		fflush(stdin);
		printf("\n\nИзбор: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '2');

	return ch;
}

char subMenuAdd()
{
	char ch;

	printf("\n1. Добавяне в началото");
	printf("\n2. Добавяне в края");
	printf("\n3. Добавяне след определен клиент");
	printf("\n0. Назад");

	do
	{
		fflush(stdin);
		printf("\n\nИзбор: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '3');

	return ch;
}

char subMenuDelete()
{
	char ch;

	printf("\n1. Изтриване на определен клиент");
	printf("\n2. Изтриване на целия списък");
	printf("\n0. Назад");

	do
	{
		fflush(stdin);
		printf("\n\nИзбор: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '2');

	return ch;
}

char subMenuSearch()
{
	char ch;

	printf("\n1. Въвеждане на ID за търсене");
	printf("\n0. Назад");

	do
	{
		fflush(stdin);
		printf("\n\nИзбор: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '1');

	return ch;
}