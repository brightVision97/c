#include "globalDefs.h"

node *makeNewClient()
{
	system("cls");
	node *newE = (node*)malloc(sizeof(node));

	printf("\n��� �� �������: ");
	fflush(stdin);
	gets(newE->d.fullName);
	strcpy(newE->d.id, getRandomID(6));
	fflush(stdin);
	printf("\n����: ");
	scanf("%f", &newE->d.sum);
	printf("\n������� �� ������ � ������� (� ������): ");
	scanf("%d", &newE->d.months);

	newE->next = NULL;
	newE->prev = NULL;
		
	return newE;
}

char *getRandomID(size_t length)
{
	const char charSet[] = 
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char *randID = NULL;
	
	if (length)
	{
		randID = malloc(sizeof(char) * (length + 1));

		if (randID)
		{
			for (unsigned int i = 0; i < length; i++)
			{
				int key = rand() % (int)(sizeof(charSet) - 1);
				randID[i] = charSet[key];
			}

			randID[length] = '\0';
		}
		else
		{
			printf("\n\n���� ���������� �����!");
			return NULL;
		}
	}
	
	return randID;
}

node *addToHead(node *head)
{
	node *newE = makeNewClient();

	if (head != NULL)
	{
		head->prev = newE;
		newE->next = head;
	}
	else
	{
		head = newE;
		exportToBinaryFile(head);
	}

	printf("\n\n�������� ���� ������� ��� �������!");

	return newE;
}

node *addToTail(node *head)
{
	node *newE = NULL, *index = head;
	int flag = 0;

	if (head == NULL && !flag)
	{
		flag = 1;
		newE = addToHead(head);
		return newE;
	}
	else
	{
		while (index->next != NULL)
			index = index->next;

		newE = makeNewClient();
		index->next = newE;
		newE->prev = index;
		printf("\n\n�������� ���� ������� ��� �������!");
	}

	return head;
}

node *insertToList(node *head)
{
	node *afterE = head, *newE = NULL;
	char input[16];

	printf("\nID �� �������, ���� ������ �� ���� ������� ���: ");
	scanf("%s", input);

	if (strcmp(input, afterE->d.id) == 0)
		newE = makeNewClient();
	else
	{
		while (afterE->next != NULL)
		{
			afterE = afterE->next;

			if (strcmp(input, afterE->d.id) == 0)
			{
				newE = makeNewClient();
				break;
			}
		}
	}

	if (newE != NULL)
	{
		newE->next = afterE->next;

		if (newE->next != NULL)
			newE->next->prev = newE;

		afterE->next = newE;
		newE->prev = afterE;

		printf("\n\n�������� ���� ������� ���� %s", afterE->d.fullName);
	}
	else 
		printf("\n\n���� ������ � ���� ID!");

	return head;
}

void searchID(node *head)
{
	if (!exists("myList.dat"))
	{
		printf("\n�� ���������� �������� ������!");
		return;
	}

	node *temp = head;
	char searchID[10];
	int flag = 0;
	
	printf("\n�������� ID �� �������� ������: ");
	scanf("%s", searchID);

	while (temp != NULL)
	{
		if (strcmp(temp->d.id, searchID) == 0)
		{
			printf("\n\n���: %s\n����: %.2f ��.\n������� �� ������: %d ������\n", 
				temp->d.fullName, temp->d.sum, temp->d.months);

			flag = 1;
			break;
		}

		temp = temp->next;
	}

	if (!flag) 
		printf("\n\n���� �������� ����������!");
}

node *deleteEntry(node *head)
{
	if (!exists("myList.dat"))
	{
		printf("\n�� ���������� �������� ������!");
		return NULL;
	}

	node *temp = head, *toDelete = NULL;
	char input[16], *client;
	int flag = 0;
	
	if (temp == NULL)
	{
		printf("\n������! ������ ������");
		return 0;
	}
	else
	{
		printf("\n�������� ID �� �������: ");
		scanf("%s", input);

		while (temp != NULL)
		{
			if (strncmp(input, temp->d.id, strlen(temp->d.id)) == 0)
			{
				flag = 1;
				toDelete = temp;
				client = temp->d.fullName;
				break;
			}
			temp = temp->next;
		}
		if (head != NULL && toDelete == head)
		{
			if (toDelete->next != NULL)
			{
				toDelete->next->prev = NULL;
				head = toDelete->next;
			}
			else head = NULL;
		}
		else
		{
			if (toDelete != NULL)
			{
				if (toDelete->prev != NULL)
					toDelete->prev->next = toDelete->next;
				if (toDelete->next != NULL)
					toDelete->next->prev = toDelete->prev;
			}
		}
		if (toDelete != NULL)
		{
			toDelete = NULL;
			free(toDelete);
			
			if (flag)
				printf("\n�������� %s � ������!", client);
		}
		if (!flag)
			printf("\n���� ������ � ������ ID!");
	}
	
	return head;
}

void destroyList(node *head)
{
	if (!exists("myList.dat"))
	{
		printf("\n�� ���������� �������� ������!");
		return;
	}

	FILE *fp = NULL;
	char input[8];

	if (head != NULL)
	{
		printf("\n������� �� ���? [��/��]: ");
		scanf("%s", input);

		if (strcmp(input, "��") == 0)
		{
			if ((fp = fopen("myList.dat", "wb")) != NULL)
			{
				memoryCleanup(head);
				printf("\n�������� ���� ������� �������!");
			}
			else printf("\n�������� ������ ��� �����������!");
		}
		else
		{
			printf("\n����������� ��������...");
			return;
		}

		fclose(fp);
	}
	else printf("\n������! ������ ������");
}

float getAverage(node *head)
{
	if (!exists("myList.dat"))
		return 0;

	int cnt = 0;
	float sum = 0;

	if (head == NULL)
	{
		printf("\n������! ������ ������");
		return 0;
	}

	while (head != NULL)
	{
		sum += head->d.sum;
		cnt++;
		head = head->next;
	}

	return (sum / cnt);
}

int exists(char *fileName)
{
	FILE *fp = NULL;

	if ((fp = fopen(fileName, "r")))
		return 1;
	
	return 0;
}

void printAvgFromFile(node *head, float avg)
{
	if (!exists("myList.dat"))
	{
		printf("\n�� ���������� �������� ������!");
		return;
	}

	if (head != NULL)
	{
		system("cls");
		printf("\n��������� �� ��������� ��� ���� ��-������ �� �������� �� ������:\n\n");

		while (head)
		{
			if (head->d.sum > avg)
				printf("\n���: %s\nID: %s\n����: %.2f ��.\n������� �� ������: %d ������\n",
				head->d.fullName, head->d.id, head->d.sum, head->d.months);

			head = head->next;
		}
	}
}

void printList(node *head)
{
	if (!exists("myList.dat"))
	{
		printf("\n�� ���������� �������� ������!");
		return;
	}
		
	int cnt = 1;

	if (!head)
		printf("\n������! ������ ������");
	else
	{
		system("cls");
		while (head)
		{
			printf("\n\t[%d]", cnt);
			printf("\n���: %s\nID: %s\n����: %.2f ��.\n������� �� ������: %d ������\n",
				head->d.fullName, head->d.id, head->d.sum, head->d.months);
			
			cnt++;
			head = head->next;
		}
	}
}

void memoryCleanup(node *head)
{
	node *freeMe = head;
	node *holdMe = NULL;

	while (freeMe != NULL)
	{
		holdMe = freeMe->next;
		free(freeMe);
		freeMe = holdMe;
	}
}