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
void create(int data) {
    struct Node *p, *q;
    p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    p->data = data;
    p->link = NULL;

    if (head == NULL) {
        head = p;
    } else {
        q = head;
        while (q->link != NULL) {
            q = q->link;
        }
        q->link = p;
    }
}

//Displaying the elements in the Linked List.
void display() {
    struct Node *p = head;
    if (p == NULL) {
        printf("\n List is Empty\n");
        return;
    }
    while (p != NULL) {
        printf("|%d|--->", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

// Inserting the new element into the Linked list in the 
// selected position
void insert() {
    struct Node *p = head, *q;
    int new_data, pos, i = 1;

    printf("\nEnter the position to insert the data:\n");
    scanf("%d", &pos);
    printf("\nEnter the data in the %d position:\n", pos);
    scanf("%d", &new_data);

    q = (struct Node*)malloc(sizeof(struct Node));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    q->data = new_data;
    q->link = NULL;

    if (pos == 1) {
        q->link = head;
        head = q;
        return;
    }

    while (p != NULL && i < pos - 1) {
        p = p->link;
        i++;
    }

    if (p == NULL) {
        printf("Invalid position!\n");
        free(q);
        return;
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
void search() {
    struct Node *p = head;
    int search_val, index = 1, found = 0;

    printf("\nEnter the element to search:\n");
    scanf("%d", &search_val);

    while (p != NULL) {
        if (p->data == search_val) {
            printf("\nThe element %d is at position %d.\n", search_val, index);
            found = 1;
        }
        p = p->link;
        index++;
    }

    if (!found) {
        printf("Element not found in the list!\n");
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

// Freeing the Linked List memory
void free_list() {
    struct Node *p = head, *temp;
    while (p != NULL) {
        temp = p;
        p = p->link;
        free(temp);
    }
    head = NULL;
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
        free_list();
	return 0;
}
