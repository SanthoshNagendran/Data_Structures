/*******************************************************************************************
* File Name          : midterm.c
* Description        : Prog8130 - Midterm: Linked Lists
*					   This program uses linked lists to hold and print a list of numbers
*					   and prints the same in desending order
*
* Author:              Santhosh Nagendran
* Date:                22-02-2019
********************************************************************************************/
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct node
{
	int num;                        //Data of the node
	struct node *nextptr;           //Address of the next node
}*stnode;

void createNodeList(int n); // function to create the list
void displayList();         // function to display the list
struct node *insert_top(int NameData, struct node *ptrHead);//function to insert in the top
void displayList1(struct node *ptrHead);// function to display the list

int main()
{
	int n;
	struct node *ptrHead = NULL;
	printf("\n\n Linked List : To create and display Singly Linked List :\n");
	printf("-------------------------------------------------------------\n");

	printf(" Input the number of nodes : ");
	scanf_s("%d", &n);

	createNodeList(n);
	printf("\n Data entered in the list : \n");
	displayList1(ptrHead);
	displayList();
	return 0;
}
/* Adds new node to the top of a list */
// FUNCTION      : insert_top()
// DESCRIPTION   : This function takes an input of Data and the pointer head 
//				   creates a new node and places on the top. 
// PARAMETERS    : struct node *ptrHead	- variable to store address of ptrHead
//				   int *NameData				- Array of Characters with data 
// RETURNS       : possibly updated pointer to the head of the list
struct node *insert_top(int NameData, struct node *ptrHead) {
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = NameData;
	temp->nextptr = ptrHead;
	ptrHead = temp;
	return ptrHead;
}
/* Adds new node to the top of a list */
// FUNCTION      : createNodeList()
// DESCRIPTION   : This function takes an number of inputs of Data and creates a list. 
// PARAMETERS    : int n				- number of items in the list
// RETURNS       : nothing
void createNodeList(int n)
{
	struct node *fnNode, *tmp, *ptrHead=NULL;
	int num, i;
	stnode = (struct node *)malloc(sizeof(struct node));

	if (stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
	{
		printf(" Memory can not be allocated.");
	}
	else
	{
		// reads data for the node through keyboard

		printf(" Input data for node 1 : ");
		scanf_s("%d", &num);
		stnode->num = num;
		stnode->nextptr = NULL; // links the address field to NULL
		tmp = stnode;
		// Creating n nodes and adding to linked list
		for (i = 2; i <= n; i++)
		{
			fnNode = (struct node *)malloc(sizeof(struct node));
			if (fnNode == NULL)
			{
				printf(" Memory can not be allocated.");
				break;
			}
			else
			{
				printf(" Input data for node %d : ", i);
				scanf_s(" %d", &num);
				if (num < tmp->num)
				{
					fnNode->num = num;      // links the num field of fnNode with num
					fnNode->nextptr = NULL; // links the address field of fnNode with NULL

					tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
					tmp = tmp->nextptr;
				}
				else
				{
					ptrHead = insert_top(num, NULL);
				}
			}
		}
	}
}
// FUNCTION      : displayList1()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//				   and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : LinkedListNodeDef *ptrHead 
// RETURNS       : void
void displayList1(struct node *ptrHead)
{
	
	struct node *tmp = ptrHead;
	if (stnode == NULL)
	{
		printf(" List is empty.");
	}
		while (tmp != NULL)
		{
			printf(" Data = %d\n", ptrHead->num);
			tmp = tmp->nextptr;
		}
}
// FUNCTION      : displayList()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//				   and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : nothing 
// RETURNS       : void
void displayList()
{
	struct node *tmp;
	if (stnode == NULL)
	{
		printf(" List is empty.");
	}
	else
	{
		tmp = stnode;
		while (tmp != NULL)
		{
			
			printf(" Data = %d\n", tmp->num);       // prints the data of current node
			tmp = tmp->nextptr;                     // advances the position of current node
		}
	}
}
