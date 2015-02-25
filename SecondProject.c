#include "stdio.h"
#include "stdlib.h"
#define INITIALSIZE 2
#define LOADFACTOR.5


typedef struct node
{
    unsigned long int value;
    struct node *next;
}hash;



/*the current size of the table*/
unsigned long int SIZE=INITIALSIZE;

/*A hashtable of pointers to nodes called hash*/
static hash* table[INITIALSIZE];

/*the counter is used for determining load factor*/
static unsigned unsigned long int counter=0;








/*the hash function that returns an index*/
unsigned long int hashNum(unsigned long int value)
{
	/*Knuth's variant*/
	/*fck modulus*/
	unsigned long int tempHashValue=(value*(value+3))%(unsigned long int)SIZE;
    return tempHashValue;

}
/*
void freeOldTable(hash *hashTable[])
{
	int tempSize=SIZE;
	unsigned long int x;
	for(x=0; x<tempSize; x++)
	{			
		hash *itr=hashTable[x]; 
		while (itr!=NULL) 
		{
			hash *tmp = itr->next;
			free(itr);
			itr = tmp;
		} 
	}
	
}*/

/*Pass the value to be inserted and the name of the hashtable*/
void chainedHashInsert(unsigned long int value, hash *hashTable[])
{
	/* tempValue is the hashed number to be inserted into the table*/
   unsigned long int tempValue = hashNum(value);
	
	
	/*if the location that we want to insert the value is empty then we do this*/
    
	if(hashTable[tempValue] == NULL)
	{
        hashTable[tempValue] = malloc(sizeof(hash));    
        hashTable[tempValue]->value = value;
        hashTable[tempValue]->next = NULL;
		return;
    }
	
	/*Otherwise we do this here*/
	else
	{
		
		/*create a pointer to a node and set it to the pointer at hashTable[tempValue]*/
        hash *hashNode = hashTable[tempValue];
		
		/*while that node pointer.next is not equal to null then do this */
        while(hashNode->next!=NULL)
		{                          
            hashNode = hashNode->next;
        }
        hashNode->next = malloc(sizeof(hash)); 
        hashNode->next->value = value;
        hashNode->next->next = NULL;
    }
}




/*Resizes the silly table*/
void resizeTable(hash *hashTable[])
{
	SIZE=SIZE*2;
	hash *temp=malloc(SIZE*sizeof(hash));
	memcpy(&table,&table,sizeof(temp));
	int x;
	for (x=0;x<SIZE;x++)
		table[x]=NULL;
	
	
	
}

/*Determines whether to resize or no */
void resizeYet()
{
	
	long double tableLoad=(long double)counter/(unsigned long int)SIZE;
	if (tableLoad>=LOADFACTOR)
	{
		resizeTable(table);
	}
}






/*Pass the value to be printed and the name of the hashtable*/
void print(unsigned long int val,hash *hashTable[])
{
	
	hash *hashMapNode = hashTable[hashNum(val)];
	
    while(hashMapNode!=NULL)
	{
        printf("%d ",hashMapNode->value);                           
        hashMapNode = hashMapNode->next;
    }

}


/* MAIN FUNCTION */
int main (int argc, char const *argv[])
{
	chainedHashInsert(5,table); 
	resizeTable(table);
	resizeTable(table);
	chainedHashInsert(6,table);
	print(6, table);
	printf("%d\n",SIZE);
 
   

   
}
