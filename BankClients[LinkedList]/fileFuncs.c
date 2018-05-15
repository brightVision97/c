#include "globalDefs.h"

void exportToBinaryFile(node *head)
{
	FILE *fp = NULL;

	if (head == NULL)
	{
		printf("Грешка! Празен списък!");
		return;
	}
	else
	{
		if ((fp = fopen("myList.dat", "wb")) != NULL)
		{
			node *current = head;
			node *holdNext = NULL;
			node *holdPrev = NULL;

			while (current != NULL)
			{
				holdNext = current->next;
				holdPrev = current->prev;

				current->next = NULL;
				current->prev = NULL;

				fseek(fp, 0, SEEK_END);
				fwrite(current, sizeof(node), 1, fp);

				current->next = holdNext;
				current->prev = holdPrev;

				holdNext = NULL;
				holdPrev = NULL;

				current = current->next;
			}

			if (ferror(fp))
				printf("\n\nВъзникна грешка с обработвания файл!");
		}
	}

	fclose(fp);
	fp = NULL;
}

node *readListFromBinaryFile(node *head)
{
	FILE *fp = NULL;

	if ((fp = fopen("myList.dat", "rb")) != NULL)
	{
		memoryCleanup(head);
		head = NULL;

		fseek(fp, 0, SEEK_END);
		long fileSize = ftell(fp);

		rewind(fp);

		int numEntries = (int)fileSize / sizeof(node);

		for (int i = 0; i < numEntries; i++)
		{
			fseek(fp, (sizeof(node) * i), SEEK_SET);
			head = readNextStructFromBinary(head, fp);
		}
	}
	else
	{
		printf("\nГрешка при отваряне на двоичния файл!");
		return NULL;
	}


	fclose(fp);
	return head;
}

node *readNextStructFromBinary(node *head, FILE *fp)
{
	if (head == NULL)
	{
		head = (node*)malloc(sizeof(node));

		fread(head, sizeof(node), 1, fp);

		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		node *index = head;
		node *newE = (node*)malloc(sizeof(node));

		while (index->next != NULL)
			index = index->next;

		fread(newE, sizeof(node), 1, fp);
		index->next = newE;
		newE->next = NULL;
		newE->prev = index;
	}

	return head;
}