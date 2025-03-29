/****************************************************************/
/*	Name	: Single Linked List 				*/
/*	Author	: Subbaramaiah Chevuru				*/
/*								*/
/****************************************************************/

//==============================================================//
//			REVISION LOG				//
//==============================================================//
// 25-01-22	-	Add Initial draft for the Single Linked //
// 			List.					//
// 25-03-29	-	Added the more functions like Create, 	//
// 			Detect and Removal of Loop and Finding  //
// 			Middle Node, Deleting a Node in given   //
// 			position and Helper functions for Search//
// 			and Sort the Singly Linked List.	//
// 								//
// 								//
//								//
//==============================================================//

//Header Files
#include <stdio.h>
#include <stdlib.h>

//Structure of the Linked List 
typedef struct List{
    int data;
    struct List *next;
}List;

//Global variables
List *head =NULL;

//Local function declarations
List* create_list();
List* insert(List*);
int search(List*);
List* middle_node(List*);
List* delete_node(List*);
List* reverse(List*);
List* loop(List*);
void create_loop(List*, int);
List* detect_loop(List*);
void display_loop(List*);
void display(List*);
void free_list(List*);
void search_sort(List*);
void sort(List*);

//Creating the Linked List
List* create_list()
{
    List *p, *q;
    int data;
    printf("\nEnter the data into Linked List:\n");
    while(1){
        scanf("%d", &data);
        if(data < 0)break;
        p = (List*)malloc(sizeof(List));
        if(p==NULL){
            return NULL;
        }
        p->data =data;
        p->next = NULL;
        if(head==NULL){
            head = p;
        }
        else{
            q->next =p;
        }
        q = p;
    }
    return head;
}

//Displaying the elements in the Linked List.
void display(List *head)
{
    List *d=head;
    if(head==NULL){
        printf("\nList is Empty...!!!\n");
        return;
    }
    printf("\nThe Linked List is :\n");
    while(d!=NULL){
        printf("%d-->", d->data);
        d = d->next;
    }
    printf("\n");
}

// Inserting the new element into the Linked list in the 
// selected position
List* insert(List* head)
{
  List *i, *in=head;
  int data, pos, j=1;
  printf("\nEntet the data to insert and position into Linked List:\n");
  scanf("%d", &data);
  scanf("%d", &pos);
  if(data < 0)return NULL;
  i = (List*)malloc(sizeof(List));
  if(i==NULL){
    return NULL;
  }
  i->data = data;
  i->next = NULL;
  if(pos == 1){
      i->next = head;
      return i;
  }
  while(j < pos-1 && in!=NULL){
    in = in->next;
    j++;
  }
  if(in == NULL){
      free(i);
      return head;
  }
  i->next = in->next;
  in->next = i;
  return head;
}

//Searching in the Linked List
int search(List* head)
{
    int sear, pos=1;
    List *s = head;
    if(head == NULL)
    {
        return -1;
    }
    printf("\nEnter the element to be search:\n");
    scanf("%d", &sear);
    while(s!=NULL){
        if(s->data == sear){
            return pos;
        }
        s = s->next;
        pos++;
    }
}

//Finding the Middle Node
List* middle_node(List* head)
{
    List *fast = head, *slow=head;
    if(head == NULL){
        return NULL;
    }
    while(fast !=NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//Delete a Node at given position
List* delete_node(List* head)
{
    List *del=head, *prev=NULL;
    int pos, i=0;
    if(head==NULL){
        return NULL;
    }
    printf("\nEntet the position of Node to delete:\n");
    scanf("%d", &pos);
    if(pos ==1){
        head = head->next;
        free(del);
        return head;
    }
    while(i<pos-1 && del!=NULL){
        prev =del;
        del = del->next;
        i++;
    }

    if(del == NULL){
        return head;
    }
    prev-> next = del->next;
    free(del);
    return head;
}

//Reverse the elements in the Linked List.
List* reverse(List *head)
{
    List *r=head, *q=NULL, *prev = NULL;
    if(head==NULL){
        return NULL;
    }
    printf("\nReversing ");
    while(r!=NULL){
        q = r->next;
        r->next = prev;
        prev = r;
        r = q;
    }
    head = prev;
    return head;
}

//Creating a loop in the List when based on user input
void create_loop(List* head, int p)
{
    List *l = head, *loopnode=NULL, *last=NULL;
    while(l!=NULL){
        if(p == l->data){
            loopnode = l;
        }
        last = l;
        l = l->next;
    }
    if(loopnode !=NULL){
        last->next = loopnode;
        printf("\nLoop created successfully...\n");
    }
    else{
        printf("\nLoop not created.\n");
    }
}

//Detect Loop in the Linked List
List* detect_loop(List *head)
{
    List *fast=head, *slow=head, *prev=NULL;
    if(head==NULL){
        return 0;
    }
    while(fast !=NULL && fast->next !=NULL){
        fast = fast->next->next;
        prev =slow;
        slow = slow->next;
        if(fast == slow){
            slow =head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return 0;
}

//Displaying the Loop elements in the Linked List.
void display_loop(List* loopnode)
{
    List *current=loopnode;
    if(loopnode==NULL){
        return;
    }
    printf("\nLoop starts from the below:\n");
    do{
        printf("%d-->", current->data);
        current = current->next;
    }while(current != loopnode);
    printf("\n");
}

//Helper function for the Loop Operations Like Create and Detect.
List* loop(List *head)
{
    List *l = head, *loopnode;
    int p, loop, i=1;
    if(head == NULL){
        return NULL;
    }

    printf("\nSelect data to create loop.\n");
    scanf("%d", &p);
    create_loop(l, p);
    loopnode = detect_loop(l);
    return loopnode;
}

//Remove the Loop in the Linked List
void remove_loop(List *loopd)
{
    List *slow = head, *fast = loopd;
    if (loopd == NULL) {
        printf("\nNo loop to remove.\n");
        return;
    }

    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
    printf("\nLoop Removed.\n");
}

//Freeing the allocated Memory for Linked List
void free_list(List* head)
{
    List *temp;
    printf("\nFreeing the Linked List....\n");
    while(head!=NULL){
        temp = head;
        head = head->next;
       free(temp);
    }
    head = NULL;
}

//Helper function for the Loop Operations Like Display and Remove
void loop_func(List *loopd)
{
    int ch;
    if(loopd!=NULL){
        printf("\nLoop is detected.\n");
    }
    else{
        printf("\nNo Loop exists.\n");
        return;
    }
    printf("\nEnter the choice \n1.Display Loop.\n2.Remove Loop.\n");
    scanf("%d", &ch);
    if (ch == 1) {
        display_loop(loopd);
    } else if (ch == 2) {
        remove_loop(loopd);
        loopd = NULL;
    }
}

//Sorting the Linked List elements using BubbleSort technique
void sort(List* head)
{
    List *s=head, *r;
    int temp;
    if(head == NULL){
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

//Helper function to perform either Search or Sort the Linked List
void search_sort(List* list)
{
    int choice, ele;
    printf("\nSelect the choice:\n1. Search\n2. Sort\n");
    scanf("%d", &choice);
    if(choice ==1){
        ele = search(list);
        if(ele>0){
            printf("\nElement is found at %d position.\n", ele);
        }
        else{
            printf("\nElement is not found...\n");
        }
    }
    else if(choice ==2){
        printf("\nThe Sorted List:\n");
        sort(list);
    }
}

//Displaying the Operations that performed in Linked List.
void info()
{
    printf("\n========================");
    printf("\nLinked List Operations..");
    printf("\n========================");
    printf("\n1. Create.");
    printf("\n2. Display.");
    printf("\n3. Insert.");
    printf("\n4. Search and Sort.");
    printf("\n5. Middle.");
    printf("\n6. Delete.");
    printf("\n7. Reverse.");
    printf("\n8. Loop.");
    printf("\n9. Loop Functions.");
    printf("\n0. Exit.");
    printf("\n========================");
}


//Main Starts here
int main() {
    int opt;
    List *list=NULL, *mid=NULL,*loopd=NULL;
    while(1){
        info();
        printf("\nSelect the Operation (1-10)..!!!\n");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:list = create_list();
            break;
            case 2:display(list);
            break;
            case 3:list = insert(list);
            display(list);
            break;
            case 4:search_sort(list);
            break;
            case 5: mid = middle_node(list);
            if(mid) printf("\nThe Middle Node is %d.\n", mid->data);
            else printf("\nThe list is empty.\n");
            break;
            case 6:list = delete_node(list);
            display(list);
            break;
            case 7:list = reverse(list);
            display(list);
            break;
            case 8:loopd = loop(list);
            break;
            case 9: loop_func(loopd);
            break;
            case 0:free_list(list);
            exit(1);
            break;
            default:
            printf("\n Thank You....!!!!\n");
        }
    }
    return 0;
}

//Ends Here
