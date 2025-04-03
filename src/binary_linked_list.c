/************************************************************************/
/*	Program Name	: Convert Decimal to Binary and Create		*/
/*			  it into Linked List and then Convert the 	*/
/*			  Linked List into Equivalent Decimal by  	*/
/*			  perform the Stack Operations like Push and 	*/
/*			  Pop.						*/
/*	Author		: Subbaramaiah Chevuru				*/
/*									*/
/************************************************************************/

//======================================================================//
//			REVISION LOG					//
//======================================================================//
//									//
//	2025-03-29	-	Initial Draft of the Program.		//
//	2025-04-03	-	Improvements for memory Leaks.		//
//									//
//									//
//======================================================================//


//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Structure to store the binary bits.
struct List {
   unsigned int bit:1;
   struct List *next;
}*head=NULL, *top=NULL, *q=NULL;


//Creating the Linked List using the Binary bits of the
//given Number
void create(int data)
{
	struct List *p = (struct List*)malloc(sizeof(struct List));
	if(p==NULL){
        return;
	}
	p->bit = data;
	p->next = NULL;
	if(head == NULL){
		head = q = p;
	}
	else{
		q->next = p;
		q = p;
	}
}


//Displaying the Linked List of the Binary bits.
void displayBinLL(struct List *head)
{
	struct List *p=head;
	if(head == NULL){
		return;
	}
	while(p != NULL){
		printf("%d---> ", p->bit);
		p = p->next;
	}
	printf("\n");
}


//Converting the Decimal Number into Binary Bits and create the
//Linked List
void decimalToBinary(int decimal)
{
	int bin[32], i = 0, j;
	if (decimal == 0) {
		create(0);
	}
	else {
		while (decimal > 0) {
			bin[i++] = decimal % 2;
			decimal /= 2;
		}
		for (j = i - 1;j >= 0; j--) {
			create(bin[j]);
		}
	}
	printf("\nThe Binary Linked List is :\n");
	displayBinLL(head);
}

//Push the Binary bits into Stack for evaluating the
//equivalent Decimal
void push(unsigned int d)
{
	struct List *s = (struct List*)malloc(sizeof(struct List));
	if(s==NULL){
		return;
	}
	s->bit = d;
	s->next = NULL;
	if(top==NULL){
		top = s;
	}
	else{
		s->next = top;
	}
	top = s;
}

//Pop the each bit stored in the stack and returns the bit
unsigned int pop()
{
	struct List *r=top;
	if(top==NULL){
		return 0;
	}
	unsigned int d = r->bit;
	top = top->next;
	free(r);
	return d;
}

//Converts the Equivalent Decimal by pushing and Popping the bits
//into the Stack.
int convertLLBinToDecimal(struct List* head)
{
	struct List *p = head;
	int dec =0, power=0;
	unsigned int Bit;
	if(head == NULL){
		return -1;
	}
	printf("\nPushing the bits into Stack...\n");
	while(p!=NULL){
		push(p->bit);
		p = p->next;
	}
	printf("\nPoping the bits from Stack and calculate decimal...\n");
	while(top!=NULL){
		Bit = pop();
		//dec = dec + Bit * pow(2, power);
		dec = (dec << 1) | Bit;
		power++;
	}
	return dec;
}

//Freeing the Linked List
void freeList(struct List **head)
{
	struct List *temp;
	printf("\nFreeing the memory......\n");
	while(*head != NULL) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;

	//Freeing the Stack
	while(top !=NULL){
		temp = top;
		top = top->next;
		free(temp);
	}
	top = NULL;
}

//Main starts here
int main()
{
	int decimal;
	printf("\nEnter the Decimal Number:\n");
	scanf("%d", &decimal);
	decimalToBinary(decimal);
	printf("\nAfter converting into decimal, value :%d:\n", convertLLBinToDecimal(head));
	freeList(&head);
	return 0;
}
//Ends Here
