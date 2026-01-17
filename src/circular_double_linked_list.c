/************************************************************************/
/*  Program Name    :   Circular Double Linked List                     */
/*  Author          :   Subbaramaiah Chevuru                            */
/*  Email           :   ram.subaram@gmail.com                           */
/************************************************************************/

/*======================================================================*/
/*                          REVISION LOG                                */
/*======================================================================*/
/*  26-01-17        -   Initial Draft of the Circular Double Linked     */
/*                      List in C.                                      */
/*                                                                      */
/*======================================================================*/

//Header files
#include<stdio.h>
#include<stdlib.h>

//Structure of Circular Doubly Linked List 
typedef struct CDLL{
    int data;
    struct CDLL *prev, *next;
}CDLL;

//Global variable
CDLL *head =NULL;

//Helper function to create a Node with Data and returns the 
//pointer to the structure.
CDLL* node_create()
{
    int data;
    printf("\nEnter the Data into Circular Doubly Linked List...\n");
    scanf("%d",&data);
    if(data < 0 ){
        return NULL;
    }
    CDLL *p = (CDLL*)malloc(sizeof(CDLL));
    if(!p){
        printf("\nMemory not allocated...\n");
        return NULL;
    }
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

//Helper function to Create the Circular Doubly Linked List
void create()
{
    CDLL *p =NULL, *q=NULL;
    do{
        p = node_create();
        if(!p){
            printf("\nNode is not created..\n");
            break;
        }
        if(head == NULL){
            head = p;
            p->prev = p;
            p->next = p;
        }
        else{
            q = head->prev;
            q->next = p;
            p->prev = q;
            p->next = head;
            head->prev = p;
        }
    }while(1);

}

//Helper function to display the Linked List in forward direction.
void display()
{
    CDLL *d=head;
    if(head == NULL){
        printf("\nCircular Doubly Linked List is Empty...\n");
        return;
    }
    do{
        printf("%d--->", d->data);
        d= d->next;
    }while(d != head);
    printf("\n");
}

//Helper function to Insert the Data into the Linked List at the 
//Begining.
void insert_at_beg()
{
    CDLL *ins = node_create();
    if(!ins){
        printf("\nNode is not created..\n");
        return;
    }
    if(head== NULL){
        head = ins;
        ins->prev = ins;
        ins->next = ins;
    }
    else{
        ins->prev = head->prev;
        head->prev->next = ins;
        head->prev =ins;
        ins->next = head;
        head = ins;
    }
}

//Helper function to Insert the Data into Linked List in the Middle 
//based on the position given by the user input.
void insert_at_middle()
{
    int i, pos;
    CDLL *inm = node_create();
    CDLL *ins = head;
    if(!inm){
        printf("\nNode is Not Created..\n");
        return;
    }
    printf("\nEnter the position to be inserted the data:\n");
    scanf("%d", &pos);
    if(head== NULL || pos <=1)
    {
        head = inm;
        inm->prev = inm;
        inm->next = inm;
    }

    for(i=1;i<pos-1 && ins->next != head;i++){
        ins = ins->next;
    }
    inm->prev = ins->next->prev;
    ins->next->prev = inm;
    inm->next = ins->next;
    ins->next = inm;
}

//Helper function to Insert the Data into the Linked List at 
//the End.
void insert_at_end()
{
    CDLL *ine = node_create();
    CDLL *in = head;
    if(!ine){
        printf("\nNode is Not Created..\n");
        return;
    }
    if(head == NULL)
    {
        head = ine;
        ine->prev = ine;
        ine->next = ine;
    }
    while(in->next != head){
        in = in->next;
    }
    ine->next = in->next;
    ine->prev = in;
    in->next = ine;
}

//Insert Functions which performs mainly the below Operations:
// 1. Insert at Begining.
// 2. Insert at Middle.
// 3. Insert at End.
// User shall select the choice to where the Data to be inserted
// into the Linked List.
void insert()
{
    int choi,data;
    printf("\n1.Insert at begining.\n 2. Insert at Middle.\n 3. Insert at End.\n");
    printf("\nEnter your choice:\n");
    scanf("%d",&choi);
    if(choi > 3){
        printf("\nBy default the node is inserted at the Node of the List..\n");
    }
    switch(choi){
        case 1: insert_at_beg();
                break;
        case 2: insert_at_middle();
                break;
        case 3: insert_at_end();
                break;
        default: insert_at_end();
    }
}

//Main starts here
int main()
{
    create();
    display();
    insert();
    display();
    return 0;
}
//End.
