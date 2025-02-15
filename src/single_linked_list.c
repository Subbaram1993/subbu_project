/************************************************************************/
/*	Program Name	:	Single Linked List			*/
/*	Author 		:	Subbaramaiah Chevuru			*/
/*	Details		:	This is a simple C Program that		*/
/*				evaluates the Single linked list.	*/
/*									*/
/************************************************************************/

/*----------------------------------------------------------------------*/
/*			Revision Log					*/
/*----------------------------------------------------------------------*/
/*	24-12-15	-	Initial Draft				*/
/*									*/
/************************************************************************/

/**/
//Header Files
#include<stdio.h>
#include<stdlib.h>

//Linked List Structure
struct LinkedList{
	int data;
	struct LinkedList *list;
}*head=NULL;

//Creating the List using the function create_list()
//It takes No Parameters and return nothing.
void create_list()
{
	struct LinkedList *p, *q, *t;
	char ch = 'y';
	do
	{
		p = (struct LinkedList*)malloc(sizeof(struct LinkedList));
		if(p == NULL)
		{
			printf("\nMemory Allocation failed....!\n");
			exit(1);
		}
		printf("\n Enter the Data in the LinkedList:\t");
		scanf("%d", &p->data);
		p->list = NULL;
		if(head == NULL)
		{
			head = p;
		}
		else
		{
			q->list = p;
		}
		q =p;
		scanf(" %c", &ch);
	}while(ch != 'n');

}

//Printing the elements in the created LinkedList 
//If No List exists, the print_list() will prints
//the message create the list first and the print.
void print_list()
{
	struct LinkedList *r=head;
	if(head == NULL)
	{
		printf("\nLinked List is Empty....! No Elements in the List...! Please make A list by calling the func: \"create_list()\"\n");
		exit(1);
	}
	else
	{
		while(r!=NULL)
		{
			printf("%d", r->data);
			if(r->list != NULL)
			{
				printf("->");
			}
			r = r->list;
		}
		printf("\n");
	}
}

//Function menu() starts here
//Its displays the some user interface messages that will 
//easily understand the user what should they want to do 
//with this program
int menu()
{
	int opt;
	printf("\n------------------------------------------------");
	printf("\n-----------    Linked List    ------------------");
	printf("\n------------------------------------------------");
	printf("\n 1. Create List				  ");
	printf("\n 2. Display List				  ");
	printf("\n------------------------------------------------");
	printf("\n Enter the choice (1 to 2) or any other selection to exit the program\n ");
	scanf("%d",&opt);
	
	return opt;
}

// Free allocated memory to avoid memory leaks
void free_list() {
    struct LinkedList *temp;
    while (head != NULL) {
        temp = head;
        head = head->list;
        free(temp);
    }
}

//Main function starts from here
int main()
{
	int choice;
        while(1)
	{	
		choice = menu();
		switch(choice)
		{
			case 1 :
				printf("\n Create the list......\n");
				create_list();
				break;
			case 2 :
				printf("\n Displaying the List..........\n");
				print_list();
				break;
			default:
				printf("\n Nothing was selected ......Exiting.....!!!\n");
				free_list();
				exit(0);
		}
	}
	return 0;
}
