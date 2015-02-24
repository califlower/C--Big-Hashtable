#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE !TRUE
#define SIZE 1000


typedef struct node
{
    long long value;
    struct node *next;
}hash;

static hash* hashTable[SIZE];


long long hashNum(long long value)
{
    return (value%SIZE);
}

void chainedHashInsert(long long value)
{
    long long tempValue = hashNum(value);
	
    if(hashTable[tempValue] == NULL)
	{                              
        hashTable[tempValue] = malloc(sizeof(hash));    
        hashTable[tempValue]->value = value;
        hashTable[tempValue]->next = NULL;
    }
	else
	{                                                          
        hash *hashNode = hashTable[tempValue];
        while(hashNode->next!=NULL)
		{                           // scrolls down the list
            hashNode = hashNode->next;
        }
        hashNode->next = malloc(sizeof(hash)); 
        hashNode->next->value = value;
        hashNode->next->next = NULL;
    }
}


/* MAIN FUNCTION */
int main (int argc, char const *argv[])
{
   

}
