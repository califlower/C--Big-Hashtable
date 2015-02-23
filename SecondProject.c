#include <stdio.h>
#include <stdlib.h>

typdef struct node				/* Define the node structure */
{
    long long data;
    struct node *next;
};

long long uniques=0
long long tablesize=1000;				/* Initial easily modified table size */
node table[tablesize]={NULL};		/*Initial table that depends on the tablesize variable. It is an array of nodes*/
			
/*long long readFile(FILE *fp)
{
	FILE *input;
	char memoryAddress[100];
	long long convAddress;
	
	if (!(input = fopen(argv[1],"r")))
	{
		printf("error\n");
		return 0;
	}
	
	if (fscanf(input, "%s", memoryAddress) != EOF)
	{
		convAddress=strtoull(*memoryAddress, NULL, 0) ;
		fclose(input);
		return convAddress;
	}
		
		return NULL;
	
	
}*/
			
			
long long hash(long long num)
{
	//unknown yet
}			
			
void insertList(long long num)
{
	/*creates the node to add and the iterator*/
	

	struct node *toInsert=(struct node *)malloc(sizeof(struct node));
	struct node *iterator;
	
	if (table[num]==NULL)
	{
		table[num]=toInsert;
		uniques++;
	}
	else
	{
		iterator=table[num];
		while (iterator!=NULL)
		{
			if (iterator->data==num)
			{
				return 0;
			}
			if (iterator->next==NULL)
			{
				toInsert->next=iterator->next;
				iterator->next=toInsert;
				return 0;
			}
			iterator=iterator->next;
		}  
	}
}

void printUnique()
{
	printf(%d,uniques);
}

int main(int argc, char** argv)
{
	
	FILE *input;
	char memoryAddress[100];
	long long convAddress;
	
	if (!(input = fopen(argv[1],"r")))
	{
		printf("error\n");
		return 0;
	}
	
	while (fscanf(input, "%s", memoryAddress) != EOF)
	{
		convAddress=strtoull(*memoryAddress, NULL, 0) ;
		long long hashNumber=hash(convAddress);
		insertList(hashNumber);
	}
	
		printUnique();
		fclose(input);
		return 0;
	
	
}