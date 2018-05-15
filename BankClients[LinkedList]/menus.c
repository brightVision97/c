#include "globalDefs.h"

char menu()
{
	char ch;

	printf("|------------------������� ������-������� �� �����------------------|\n");
	printf("| 1. �������� �� ��� ������                                         |\n");
	printf("| 2. ������� �� ������                                              |\n");
	printf("| 3. ���������                                                      |\n");
	printf("| 4. ��������� �� ������                                            |\n");
	printf("| 0. ����� � ����� �� �������                                       |\n");
	printf("|-------------------------------------------------------------------|\n");

	do
	{
		fflush(stdin);
		printf("\n�����: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '4');

	return ch;
}

char subMenuPrint()
{
	char ch;

	printf("\n1. ��������� �� ����� ������");
	printf("\n2. ��������� �� ������� ��������");
	printf("\n0. �����");

	do
	{
		fflush(stdin);
		printf("\n\n�����: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '2');

	return ch;
}

char subMenuAdd()
{
	char ch;

	printf("\n1. �������� � ��������");
	printf("\n2. �������� � ����");
	printf("\n3. �������� ���� ��������� ������");
	printf("\n0. �����");

	do
	{
		fflush(stdin);
		printf("\n\n�����: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '3');

	return ch;
}

char subMenuDelete()
{
	char ch;

	printf("\n1. ��������� �� ��������� ������");
	printf("\n2. ��������� �� ����� ������");
	printf("\n0. �����");

	do
	{
		fflush(stdin);
		printf("\n\n�����: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '2');

	return ch;
}

char subMenuSearch()
{
	char ch;

	printf("\n1. ��������� �� ID �� �������");
	printf("\n0. �����");

	do
	{
		fflush(stdin);
		printf("\n\n�����: ");
		scanf("%c", &ch);
	} while (ch < '0' || ch > '1');

	return ch;
}