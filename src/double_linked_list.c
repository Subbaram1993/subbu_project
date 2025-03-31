/************************************************************************/
/*	Program Name	:	Double Linked List in C			*/
/*	Author		: 	Subbaramaiah Chevuru			*/
/* 									*/
/*									*/
/************************************************************************/

//======================================================================//
//			REVISION LOG					//
//======================================================================//
//									//
//	2025-03-31	-	Initial Draft of the Program.		//
//									//
//									//
//									//
//======================================================================//

//Header Files
#include <stdio.h>
#include <stdlib.h>


//Structure Declaration 
typedef struct DLL{
    int data;
    struct DLL *prev, *next;
}Double;
 

//Global variable
Double *head = NULL;

//Helper functions to perform the Operations in 
//Double Linked List
Double* create_list();
Double* insert(Double*);
int search(Double*, int);
Double* middle_node(Double*);
Double* delete_node(Double*);
Double* reverse(Double*);
void display(Double*);
void free_list(Double*);
void search_sort(Double*);
void sort(Double*);

//Creating the Double Linked List 
Double* create_list()
{
	Double *p, *q;
	int data;
	printf("\nEnter the data into Doubly Linked List:\n");
	while(1){
		scanf("%d", &data);
		if(data<0) break;
		p = (Double*)malloc(sizeof(Double));
		if(p==NULL){
			printf("\nMemory not allocated.\n");
			return NULL;
		}
		p->data = data;
		p->prev= p->next = NULL;
		if(head == NULL){
			head = p;
		}
		else{
			q->next = p;
			p->prev = q;
		}
		q = p;
	}
	return head;
}

//Displaying the elements in the Linked List
void display(Double *head)
{
	Double *d=head, *pre=NULL;
	if(head==NULL){
		return;
	}
	printf("\nForward Traversal:\n");
	while(d!=NULL){
		pre =d;
		printf("%d<===>", d->data);
		d = d->next;
	}
	// printf("\nBackward Traversal:\n");
	// while(pre!=NULL){
	// printf("%d<===>", pre->data);
	// pre = pre->prev;
	// }
}

// Helper function to insert an new element at any position
// in the Double Linked List 
Double* insert(Double *head)
{
	int data, pos,i=1;
	Double *ins, *n=head, *t=NULL;
	if(head == NULL){
		printf("\nList is Empty.\n");
		return NULL;
	}
	printf("\nEnter the data to be inserted.\n");
	scanf("%d", &data);
	printf("\nEnter the position to be inserted.\n");
	scanf("%d", &pos);
	ins = (Double*)malloc(sizeof(Double));
	if(ins == NULL){
		printf("\nMemeory not allocated.\n");
		return NULL;
	}
	ins->data = data;
	ins->prev = ins->next = NULL;
	if(pos==1){
		ins->next = head;
		head->prev = ins;
		head = ins;
		return head;
	}
	while(i<pos-1 && n!=NULL){
		i++;
		n = n->next;
	}
	ins->next = n->next;
	if(n->next != NULL){
		n->next->prev =ins;
	}
	n->next = ins;
	ins->prev = n;
	return head;
}

//Freeing the memory by deleting the Double Linked List
void free_list(Double* head)
{
	Double *temp;
	printf("\nFreeing the Linked List....\n");
	while(head!=NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	head = NULL;
}

//Reverse the elements in the Linked List
Double* reverse(Double *head)
{
	Double *r=head, *temp=NULL;
	if(head==NULL){
		return NULL;
	}
	while(r!=NULL){
		temp = r->prev;
		r->prev = r->next;
		r->next = temp;
		r = r->prev;
	}
	if(temp!=NULL){
		head = temp->prev;
	}
	return head;
}

//Search an element in the Linked List
int search(Double *head, int ele)
{
	int pos=1;
	if(head == NULL){
		printf("\nList is Empty");
		return -1;
	}
	Double *s=head, *r=NULL;
	while(s!=NULL){
		if(ele == s->data){
			return pos;
		}
		pos++;
		s =s->next;
	}
	return 0;
}

//Sorting the unsorted Double Linked List
void sort(Double *head)
{
	Double *s=head, *r=NULL;
	int temp;
	if(head==NULL){
		printf("\nList is Empty.\n");
		return;
	}
	while(s!=NULL){
		r = s->next;
		while(r!=NULL){
			if(s->data > r->data){
				temp = s->data;
				s->data = r->data;
				r->data = temp;
			}
			r = r->next;
		}
		s = s->next;
	}
	printf("\n");
}

//Helper function to search an element and sorts the unsorted 
//Double Linked List
void search_sort(Double *head)
{
	int flag, opt, ele;
	printf("\nEnter the choice :\n1. Search\n2. Sort\n");
	scanf("%d",&opt);
	if(opt==1){
		printf("\nEnter the data to be search:\n");
		scanf("%d", &ele);
		flag = search(head, ele);
		if(flag>0){
			printf("\nThe Data %d is  at %d position in List.\n", ele, flag);
		}
		else{
			printf("\nThe Data is not found.\n");
		}
	}
	else if(opt==2){
		sort(head);
		printf("\nAfter Sorting the Data in the List....\n");
		display(head);
	}
} 

//Find and return the pointer that middle node of the Double
//Linked List
Double* middle_node(Double *head)
{
	Double *fast = head, *slow=head;
	if(head == NULL){
		return NULL;
	}
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//Delete a node at a given position by user input.
Double* delete_node(Double *head)
{
	int pos,i;
	Double *d=head, *last=NULL;
	if(head == NULL){
		return NULL;
	}
	printf("\nEnter the position to be deleted in DLL.\n");
	scanf("%d",&pos);
	if(pos==1){
		head = head->next;
		if(head !=NULL){
			head->prev = NULL;
		}
		free(d);
		return head;
	}
	for(i=1;i<pos && d!=NULL;i++){
		last = d;
		d = d->next;
	}
	if(d==NULL){
		return head;
	}
	last->next = d->next;
	if(d->next !=NULL){
		d->next->prev = last;
	}
	free(d);
	return head;
}

//Displays the Operations performed by the Double Linked
//List
void info()
{
	printf("\n<=================================>");
	printf("\n< Double Linked List Operations..=>");
	printf("\n<=================================>");
	printf("\n<= 1. Create.\t\t\t\t     =>");
	printf("\n<= 2. Display.\t\t\t\t     =>");
	printf("\n<= 3. Insert.\t\t\t\t     =>");
	printf("\n<= 4. Search and Sort.\t\t     =>");
	printf("\n<= 5. Middle.\t\t\t\t     =>");
	printf("\n<= 6. Delete.\t\t\t\t     =>");
	printf("\n<= 7. Reverse.\t\t\t\t     =>");
	printf("\n<= 0. Exit.\t\t\t\t\t     =>");
	printf("\n<=================================>");
}

//Main Starts here
int main() 
{
	int opt;
	Double *list=NULL, *mid=NULL, *del=NULL;
	while(1){
		info();
		printf("\nSelect the Operation (1-7)..!!!\n");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:list = create_list();
			       break;
			case 2:display(list);
			       break;
			case 3:list= insert(list);
			       break;
			case 4:search_sort(list);
			       break;
			case 5:mid = middle_node(list);
			       if(mid){
				       printf("\nThe Middle Node is %d\n", mid->data);
			       }
			       else{
				       printf("\nThe list is Empty.\n");
			       }
			       break;
			case 6:del = delete_node(list);
			       display(del);
			       break;
			case 7:list = reverse(list);
			       break;
			case 0:free_list(list);
			       exit(1);
			default:
			       printf("\n Thank You....!!!!\n");
		}
	}
	return 0;
}

//Main Ends Here
 
