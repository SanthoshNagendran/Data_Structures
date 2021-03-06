/*******************************************************************************
* File Name          : hashAssignmentV2.cpp
* Description        : Implemenation of a hash skelleton
*
* Author:              Santhosh Nagendran
* Date:                Mar 17, 2018
******************************************************************************
*/

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

unsigned int putIntoHashTable(char *ptrInputData, unsigned int bufferLength);    // function to add to hash table
unsigned int getFromHashTable(char *ptrOutputData, unsigned int bufferLength);   // function to retrieve data from hash table
int find(struct myHashStruct *list, int key);
struct myHashStruct* get_element(struct myHashStruct *list, int find_index);

#define INPUT_BUFFER_SIZE         200             // local buffer used for adding data to the hash table (there is no reason in this assignment to change this value)

#define HASH_SIZE    5                          // size of hash table to be used (for testing I suggest making this number much lower)

// data structure used to keep track of hashed data
struct myHashStruct {
	int key;
	char *ptrBuffer = NULL;                       // pointer to data stored in hash (you will need to malloc space for string to be stored)
	struct myHashStruct *ptrNextHashData = NULL;  // pointer to next item in this hash bucket (or NULL if no more)
};

struct arrayitem
{
	struct myHashStruct *head;
	struct myHashStruct *tail;
};

struct arrayitem *array;           // create an empty hash table structure (note this is basically an arrary of linked list heads)

int main()
{
	char    inputBuffer[INPUT_BUFFER_SIZE];
	
	array = (struct arrayitem*) malloc(HASH_SIZE * sizeof(struct arrayitem));
	// initialize the hash table to empty one
	for (int i = 0; i < HASH_SIZE; i++)
	{
		array[i].head = NULL;
		array[i].tail = NULL;
	}
	// add to hash table loop
	while (1)
	{
		printf("enter data to be added to hash table or exit when done\n");

		// get strings from the console and place in hash until nothing entered
		scanf_s("%s", inputBuffer, INPUT_BUFFER_SIZE);

		// stop adding data into hash table when "exit" is entered
		if (strcmp(inputBuffer, "exit") == 0)
			break;

		if (putIntoHashTable(inputBuffer, strlen(inputBuffer)) == HASH_SIZE)
			printf("Error putting into hash table\n");
	}
	// check if data is in hash table
	while (1)
	{
		unsigned int hashIndexNumber = 0;

		printf("Enter a data to find and delete, done when complete\n");

		// get strings from the console and check if in hash table
		scanf_s("%s", inputBuffer, INPUT_BUFFER_SIZE);

		// stop adding data into hash table when "done" is entered
		if (strcmp(inputBuffer, "done") == 0)
			break;

		if ((hashIndexNumber = getFromHashTable(inputBuffer, strlen(inputBuffer))) == HASH_SIZE)
		{
			
			printf("%s not found in hash table\n", inputBuffer);
		}
		else
		{
			printf("%s found in hash table at %u\n", inputBuffer, hashIndexNumber);
		}
	}
	return 0;
}

// FUNCTION      : myHashFunction
// DESCRIPTION   :
//   Calculate a hash value to use in storing the data into the hash table
// PARAMETERS    :
//   ptrInputBuffer - a pointer to the buffer to be put into the hash table
//
// RETURNS       :
//   Hash value calculated ( HASH_SIZE on failure)

unsigned int myHashFunction(char *ptrInputBuffer)
{
	unsigned int calculatedHashValue = 0;

	// add code to create a hashed value here!!!

	int i;

	for (i = 0; i < strlen(ptrInputBuffer); i++)
		calculatedHashValue = calculatedHashValue + ptrInputBuffer[i];

	// make sure if hash value is bigger than the table size, the value wraps
	return calculatedHashValue % HASH_SIZE;
}

// FUNCTION      : putIntoHashTable
// DESCRIPTION   :
//   Put the supplied data into a hash table
// PARAMETERS    :
//   ptrInputBuffer - a pointer to the buffer to be put into the hash table
//   bufferLength   - how many characters are in the buffer being put into the hash table
//
// RETURNS       :
//   Hash value used ( HASH_SIZE on failure)

unsigned int putIntoHashTable(char *ptrInputData, unsigned int bufferLength)
{
	unsigned int hashValue = myHashFunction(ptrInputData);
	struct myHashStruct *list = (struct myHashStruct*) array[hashValue].head;

	struct myHashStruct *item = (struct myHashStruct*) malloc(sizeof(struct myHashStruct));
	item->ptrBuffer = (char *)malloc(30);
	item->key = bufferLength;
	strcpy_s(item->ptrBuffer, 30, ptrInputData);
	item->ptrNextHashData = NULL;
	if (list == NULL)
	{
		array[hashValue].head = item;
		array[hashValue].tail = item;
		printf("inserting the data %s @ %d\n", array[hashValue].tail->ptrBuffer, hashValue);
	}
	else
	{
		int find_index = find(list, bufferLength);
		if (find_index == -1)
		{
			array[hashValue].tail->ptrNextHashData = item;
			array[hashValue].tail = item;
			printf("inserting the same hash key data %s @ %d\n", array[hashValue].tail->ptrBuffer, hashValue);
		}
		else
		{

			struct myHashStruct *element = get_element(list, find_index);
			element->ptrBuffer = ptrInputData;
			printf("inserting the same hash key data %s \n", element->ptrBuffer);
		}

	}
	// add code to put data into the hash table!!!
	
	return array[hashValue],hashValue;
}

// FUNCTION      : getFromHashTable
// DESCRIPTION   :
//   Read as much data as there is room for from the hash table
// PARAMETERS    :
//   ptrOutputBuffer - a pointer to the buffer to place the data read from hash table
//   bufferLength    - maxiumum number of characters that can be read
//
// RETURNS       :
//   Hash value used ( return HASH_SIZE value on failure)

unsigned int getFromHashTable(char *ptrOutputData, unsigned int bufferLength)
{
	
	unsigned int hashValue = myHashFunction(ptrOutputData);
	
	struct myHashStruct *list = (struct myHashStruct*)array[hashValue].head;
	if (list == NULL)
	{
		return HASH_SIZE;
	}
	else
	{
		int find_index = find(list, bufferLength);

		if (find_index == -1)
		{
			printf("the data you entered doesn't match\n");
			return HASH_SIZE;
		}
		else
		{
			struct myHashStruct *temp = list;
			if (strcmp(temp->ptrBuffer,ptrOutputData)==0)
			{
				return hashValue;
			}
			else
			{
				return HASH_SIZE;
			}
		}

	}
}
// FUNCTION      : find
// DESCRIPTION   :
//   this helps me to find the similar key data is already exist or not
// PARAMETERS    :
//	 list - the actual hash list
//   ptrOutData - a pointer to the buffer to be put into the hash table
//
// RETURNS       :
//   retval 
int find(struct myHashStruct *list, int key)
{
	int retval = 0;
	struct myHashStruct *temp = list;
	while (temp != NULL)
	{
		if (temp->key == key)
		{
			return retval;
		}
		temp = temp->ptrNextHashData;
		retval++;
	}
	return -1;
}
// FUNCTION      : get_element
// DESCRIPTION   :
//   this helps me to get the next data entered by the user
// PARAMETERS    :
//	 list - the actual hash list
//   find_index - index value check of the enterd input data
//
// RETURNS       :
//   temp 
struct myHashStruct* get_element(struct myHashStruct *list, int find_index)
{
	int i = 0;
	struct myHashStruct *temp = list;
	while (i != find_index)
	{
		temp = temp->ptrNextHashData;
		i++;
	}
	return temp;
}
