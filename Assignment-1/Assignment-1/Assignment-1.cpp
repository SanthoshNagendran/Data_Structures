/*******************************************************************************************
* File Name          : Assignment 1.c
* Description        : Prog8130 - Assignment 1: Linked Lists
*					   This program uses linked lists to hold and print a list of words
*					   organized by index number assosciated with each word. Each word can
*					   consist of maximum 30 characters.
*
* Author:              Santhosh Nagendran
* Date:                20-01-2019
********************************************************************************************/
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define NUMBER_OF_DATA_ITEMS   10					// the number of data items to be used in list

// structure/typedef used for holding data
typedef struct {
	char name[30];
	int index;
} inputData;

// definition of linked list data nodes
typedef struct LinkedListNode {
	struct LinkedListNode		*ptrNextNode;		// pointer to next node in list (NULL if the end)
	char						*NameData[30];
	char *NameData1;// the name to be stored (no need to store index)
} LinkedListNodeDef;

// prototypes
LinkedListNodeDef *AddToLinkedList(LinkedListNodeDef *ptrHead, char *NameData, int DataIndex);
void PrintLinkedList(LinkedListNodeDef *ptrHead);
LinkedListNodeDef *insert_top(char *, LinkedListNodeDef *);
LinkedListNodeDef *insert_bottom(char *, LinkedListNodeDef *);
LinkedListNodeDef *insert_after(char *, int, LinkedListNodeDef *);
LinkedListNodeDef *insert_before(char *, char *, LinkedListNodeDef *);
LinkedListNodeDef *remove(LinkedListNodeDef *);


int count = 0, a = 1;
inputData iData[10] = {
		{ "car", 8 },
		{ "kiwi", 1 },
		{ "butter", 1 },
		{ "milk", 6 },
		{ "snake", 7 },
		{ "chocolate", 5 },
		{ "airplane", 8 },
		{ "carrot", 7 },
		{ "candy", 6 },
		{ "fish", 4 }
};


/*Correct order after inserting into list is :
1. butter
2. fish
3. kiwi
4. car
5. milk
6. chocolate
7. candy
8. snake
9. carrot
10. airplane
*/

/* Adds new node to the top of a list */
// FUNCTION      : insert_top()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and the pointer head 
//				   creates a new node and places on the top. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
//				   char *NameData				- Array of Characters with data 
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef *insert_top(char *NameData, LinkedListNodeDef *ptrHead) {
	LinkedListNodeDef *temp;
	count++;
	temp = (LinkedListNodeDef *)malloc(sizeof(LinkedListNodeDef));
	temp->NameData[10] = NameData;
	temp->ptrNextNode = ptrHead;
	ptrHead = temp;
	return ptrHead;
}


/* Add a new node to the bottom of a list */
// FUNCTION      : insert_bottom()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and the pointer head 
//				   creates a new node and places on the bottom. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
//				   char *NameData				- Array of Characters with data 
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef  *insert_bottom(char *NameData, LinkedListNodeDef *ptrHead) {
	LinkedListNodeDef *temp1 = ptrHead;
	LinkedListNodeDef *temp;
	count++;
	while (temp1 != NULL && temp1->ptrNextNode != NULL) {
		temp1 = temp1->ptrNextNode;
	}

	temp = (LinkedListNodeDef *)malloc(sizeof(LinkedListNodeDef));
	temp->NameData[10] = NameData;
	temp->ptrNextNode = NULL;
	if (temp1 != NULL)
		temp1->ptrNextNode = temp;
	else
		ptrHead = temp;
	return ptrHead;
}

/* Add a new node after an element in the list */
// FUNCTION      : insert_after()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and the pointer head 
//				   creates a new node and place the created node in a decided position after the destination. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
//				   char *NameData				- Array of Characters with data - source 
//				   int count					- destination index - destination
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef *insert_after(char *NameData, int count, LinkedListNodeDef *ptrHead) {
	int a = 0;
	LinkedListNodeDef *temp;
	LinkedListNodeDef *temp1;

	temp = (LinkedListNodeDef *)malloc(sizeof(LinkedListNodeDef));
	temp->NameData[10] = 0;
	temp->ptrNextNode = ptrHead;

	ptrHead = temp;

	temp = ptrHead->ptrNextNode;
	ptrHead->NameData[10] = ptrHead->ptrNextNode->NameData[10];
	ptrHead->ptrNextNode = temp->ptrNextNode;
	free(temp);


	temp1 = ptrHead;
	while (a != (count - 2)) {
		temp1 = temp1->ptrNextNode;
		a++;
	}
	temp = (LinkedListNodeDef *)malloc(sizeof(LinkedListNodeDef));
	temp->NameData[10] = NameData;
	temp->ptrNextNode = temp1->ptrNextNode;
	temp1->ptrNextNode = temp;
	count++;
	return ptrHead;
}

/* Add a new node before an element in the list */
// FUNCTION      : insert_before()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and the pointer head 
//				   creates a new node and place the created node in a decided position before the destination. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
//				   char *NameData				- Array of Characters with data - source 
//				   char *NameData1				- Array of Characters with data - destination
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef * insert_before(char *NameData, char *NameData1, LinkedListNodeDef *ptrHead) {
	LinkedListNodeDef *temp1 = ptrHead;
	LinkedListNodeDef *temp;
	while (temp1->ptrNextNode->NameData[10] != NameData1) {
		temp1 = temp1->ptrNextNode;
	}
	temp = (LinkedListNodeDef *)malloc(sizeof(LinkedListNodeDef));
	temp->NameData[10] = NameData;
	temp->ptrNextNode = temp1->ptrNextNode;
	temp1->ptrNextNode = temp;
	return ptrHead;
}

/* Remove an element from a linked list */
// FUNCTION      : remove()
// DESCRIPTION   : This function takes the pointer head 
//				   Deletes the current node whenever it is called. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef * remove(LinkedListNodeDef *ptrHead) {
	if (ptrHead == NULL)
		return NULL;
	if (ptrHead->ptrNextNode == NULL)
	{
		delete ptrHead;
		return NULL;
	}
	LinkedListNodeDef *second_last = ptrHead;
	while (second_last->ptrNextNode->ptrNextNode != NULL)
		second_last = second_last->ptrNextNode;
	delete (second_last->ptrNextNode);
	second_last->ptrNextNode = NULL;
	return(ptrHead);
}


int main(void) {
	int i;
	struct LinkedListNode		*ptrHead = NULL;
	printf("Data before Linked List is:\n");

	for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++)
		printf("%s , %d\n", iData[i].name, iData[i].index);

	for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++)
	{
		ptrHead = AddToLinkedList(ptrHead, iData[i].name, iData[i].index);

		if (i == 0)
		{
			ptrHead = insert_top(iData[i].name, ptrHead);
			ptrHead = remove(ptrHead);
		}
		else if (i == 1)
		{
			ptrHead = insert_top(iData[i].name, ptrHead);
			ptrHead = remove(ptrHead);
		}
		else if (i > 1)
		{
			if (count > iData[i].index)
			{
				if (iData[i].index == 1)
				{
					ptrHead = insert_top(iData[i].name, ptrHead);
					ptrHead = remove(ptrHead);
				}
				else
				{
					ptrHead = insert_after(iData[i].name, iData[i].index, ptrHead);
					ptrHead = remove(ptrHead);
				}

			}
			else if (count < iData[i].index)
			{
				ptrHead = insert_bottom(iData[i].name, ptrHead);
				ptrHead = remove(ptrHead);
			}
			else if (count == iData[i].index)
			{
				ptrHead = insert_after(iData[i].name, iData[i].index, ptrHead);
				ptrHead = remove(ptrHead);
			}

		}
	}
	ptrHead = insert_after(iData[7].name, 9, ptrHead);
	ptrHead = remove(ptrHead);
	PrintLinkedList(ptrHead);
}


// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an index and 
//				   places them in a linked list organized by priority of index number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
//				   char *NameData				- Array of Characters with data 
//		           int DataIndex				- Index of data
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef *AddToLinkedList(LinkedListNodeDef *ptrHead, char *NameData, int DataIndex) {


	LinkedListNodeDef *temp1 = ptrHead;
	LinkedListNodeDef *temp;
	while (temp1 != NULL && temp1->ptrNextNode != NULL) {
		temp1 = temp1->ptrNextNode;
	}

	temp = (LinkedListNodeDef *)malloc(sizeof(LinkedListNodeDef));
	temp->NameData[10] = NameData;
	temp->ptrNextNode = NULL;
	if (temp1 != NULL)
		temp1->ptrNextNode = temp;
	else
		ptrHead = temp;
	return ptrHead;
}

// FUNCTION      : PrintLinkedList()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//				   and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : LinkedListNodeDef *ptrHead 
// RETURNS       : void
void PrintLinkedList(LinkedListNodeDef *ptrHead) {

	LinkedListNodeDef *temp1 = ptrHead;
	while (temp1 != NULL) {
		printf("the strings in the list are %s\n", temp1->NameData[10]);
		temp1 = temp1->ptrNextNode;

	}
}
