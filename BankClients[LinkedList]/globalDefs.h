#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define IDSIZE 20
#define NAMESIZE 50

typedef struct client
{
	char id[IDSIZE + 1], fullName[NAMESIZE + 1];
	int months;
	float sum;
} data;

typedef struct item
{
	data d;
	struct item *next;
	struct item *prev;
} node;

node *makeNewClient();
node *addToHead(node *head);
node *addToTail(node *head);
node *insertToList(node *head);
node *deleteEntry(node *head);
node *readNextStructFromBinary(node *head, FILE *fp);
node *readListFromBinaryFile(node *head);
void destroyList(node *head);
void printAvgFromFile(node *head, float avg);
void printList(node *head);
void memoryCleanup(node *head);
void exportToBinaryFile(node *head);
void searchID(node *head);
char menu();
char subMenuPrint();
char subMenuAdd();
char subMenuDelete();
char subMenuSearch();
char *getRandomID(size_t length);
float getAverage(node *head);
int exists(char *fileName);