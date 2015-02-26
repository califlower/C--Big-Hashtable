#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define LOADFACTOR .5




typedef struct node
{
    unsigned long long value;
    struct node *next;
}hash;




/*the current size of the table initialized to 1000*/
unsigned long long SIZE=1000;

/*A hashtable of pointers to nodes called hash*/
hash* table;

/*the counter is used for determining load factor*/
static unsigned long long counter=0;
static unsigned long long uniques=0;




void createTable()
{
	table=calloc(SIZE,sizeof(hash));
}






/*the hash function that returns an index*/
unsigned long long hashNum(unsigned long long value)
{
	/*Knuth's variant*/
	/*fck modulus*/
	unsigned long long tempHashValue=(value*(value+3))%(unsigned long long)SIZE;
    return tempHashValue;
}


/*Pass the value to be inserted and the name of the hashtable*/
void chainedHashInsert(unsigned long long value, hash *hashTable[])
{
	/* tempValue is the hashed number to be inserted into the table*/
   unsigned long long tempValue = hashNum(value);

	
	
	/*if the location that we want to insert the value is empty then we do this*/
    
	if(hashTable[tempValue] == NULL)
	{
		/*Counts unique entries*/
		uniques++;
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
		
		/*Doesn't store duplicates*/
		if (hashNode->value==value)
		{
			return;
		}
		
		/*while that node pointer.next is not equal to null then do this */
        while(hashNode->next!=NULL)
		{   

            hashNode = hashNode->next;
			/*Doesn't Store Duplicates*/
			if (hashNode->value==value)
			{
				return;
			}
        }
        hashNode->next = malloc(sizeof(hash)); 
        hashNode->next->value = value;
        hashNode->next->next = NULL;
		
		/*Counts uniques*/
		uniques++;
    }
}




/*Resizes the silly table*/
void resizeTable()
{

	
	
}

/*Determines whether to resize or no */
void resizeYet()
{
	
	long double tableLoad=(long double)counter/(unsigned long long)SIZE;
	if (tableLoad>=LOADFACTOR)
	{
		resizeTable();
	}
}






/*Pass the value to be printed and the name of the hashtable*/
void print(unsigned long long val,hash *hashTable[])
{
	
	int x;
	for (x=0;x<SIZE;x++)
	{
		if (table[x]!=0)
			printf("poop");
		
	}
	
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
 	
	createTable();
	chainedHashInsert(5,&table);
	print(5,&table);
	resizeTable();
	/*FILE *fp=fopen(argv[1],"r");
	if (!(fp = fopen(argv[1],"r")))
	{
		printf("error\n");
		return 0;
	}

	
	char key[20];
	
	while( fscanf(fp, "%s", key) != EOF)        
		{     
		unsigned long long number=strtoull (key,NULL,0);
		chainedHashInsert(number,table);
		}                    
	printf("Unique numbers \n");
	printf("%lld\n", uniques);
	fclose(fp);*/
	//resizeTable(table);
	return 0;


   
}
