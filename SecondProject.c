#include <stdio.h>
#include <stdlib.h>

typdef struct node				/* Define the node structure */
{
    long long data;
    struct node *next;
}
*head;

long long uniques=0
long long tablesize=0;				/* Initial easily modified table size */
node table[tablesize];				/*Initial table that depends on the tablesize variable. It is an array of nodes*/
			
long long readFile(FILE *fp)
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
	}
			   
	fclose(input);

	return convAddress;
	

	
}
			

			
long long hash(long long num)
{
	
}			
			
void insertList(int num)
{
	/*creates the node to add and the iterator*/
	struct node *toInsert=(struct node *)malloc(sizeof(struct node));
    struct node *iter;
	
	/*adds num to the node to insert and makes the iterator at the head*/
	toInsert->data=num;
    iter=head;
	
	/* if linked list is empty or the first element is larger than the input*/
	
	if (iter==NULL || head->data>num)
	{
		head=toInsert;
		head->next=iter;
		
		
	}
	
	/* else if the first is a duplicate*/
	else if (iter->data==num)
	{
		return;
	}
	else
	{
		/* traverse while it is not null*/
		while (iter!=NULL)
		{   
	/* duplicate check*/
			if (iter->data==num)
			{
				return;
			}				
			if (iter->data <=num && (iter->next == NULL || iter->next->data > num)) 
			{
				toInsert->next=iter->next;
				iter->next=toInsert;
				return;
			}
			iter=iter->next;
		}
	}
	
	
	

}

void hashInsertion(int num)
{
	int probe = (num)%1000;                                  
    while (table[probe]!=0)
	{   
		if (table[probe]==num)
		{
			printf("duplicate\n");
			return;
		}
        probe = (probe+1)%1000;                 
    }
    table[probe] = num;

}

void printUnique()
{
	
}