/****************************************************************/
/*	Name	: Single Linked List for n elements in V2	*/
/*	Author	: Subbaramaiah Chevuru				*/
/*								*/
/****************************************************************/

//==============================================================//
//			REVISION LOG				//
//==============================================================//
// 25-01-22	-	Add Initial draft for the Single Linked //
// 			List version2				//
//								//
//==============================================================//

//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Structure of the Linked List 
struct Node{
	int data;
	struct Node *link;
}*head=NULL;

//Creating the Linked List 
void create(int data)
{
	struct Node *p, *q;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = data;
	p->link = NULL;
	if(head == NULL)
	{
		head = p;
	}
	else{
		q->link = p;
	}
	q = p;

}

//Displaying the elements in the Linked List.
void display()
{
	struct Node *p=head;
	if(head == NULL)
	{
		printf("\n List is Empty\n");
		exit(1);
	}
	else{
		while(p!=NULL)
		{
			printf("|%d|--->",p->data);
			p = p->link;
		}
	}
	printf("\n");
}

// Inserting the new element into the Linked list in the 
// selected position
void insert()
{
	struct Node *p=head, *q;
	int new_data, pos, i=1;
	printf("\nEnter the position to insert the data:\n");
	scanf("%d", &pos);
	printf("\nEnter the data in the %d position:\n", pos);
	scanf("%d", &new_data);
	q = (struct Node*)malloc(sizeof(struct Node));
	q->data = new_data;
	q->link = NULL;
	if(pos==1)
	{
		q->link = head;
		head = q;
		return;
	}
	else
	{
		while(p!=NULL && i<pos-1)
		{
			p = p->link;
			i++;
		}
	}
	q->link = p->link;
	p->link = q;

}

//Reverse the elements in the Linked List.
void reverse()
{
	struct Node *r=head, *t,*p=NULL;
	if(head==NULL)
	{
		printf("\n List is Empty....\n");
		exit(1);
	}
	else
	{
		while(r!=NULL)
		{
			t= r->link;
			r->link =p;
			p =r;
			r=t;
		}
	}
	head = p;
}

//Searching the element and prints the position 
void search()
{
	struct Node *p=head,*t;
	int search, index=1;
	printf("\n Enter the element to be search:\n");
	scanf("%d",&search);
	while(p!=NULL)
	{
		if(p->data == search)
		{
			printf("\n The element %d is at position %d.\n", search, index);
		}
		p = p->link;
		index++;
	}
}

//Sorting the elements in the Linked List using Bubble sort 
//Technique.
void sort()
{
	struct Node *p=head, *r;
	int temp;
	if(head==NULL)
	{
		exit(1);
	}
	else
	{
		while(p!=NULL)
		{
			r = p->link;
			while(r!=NULL)
			{
				if(p->data > r->data)
				{
					temp = p->data;
					p->data = r->data;
					r->data = temp;
				}
				r = r->link;
			}
			p=p->link;
		}
	}
	printf("\n");
}

//Main Function starts here
int main()
{
	int n,i,temp;
	printf("\n Enter the number of elements in Linked List.\n");
	scanf("%d",&n);
	printf("\n Enter the nodes into the Linked List.\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		create(temp);
	}
	display();
	insert();
	display();
	search();
	sort();
	display();
	reverse();
	display();
	return 0;
}
