#ifndef binary_linked_list_H
#define binary_linked_list_H

void create(int data);
void displayBinLL(struct List *head);
void decimalToBinary(int decimal);
void push(unsigned int d);
unsigned int pop();
int convertLLBinToDecimal(struct List* head);
void freeList(struct List **head);
int main();

#endif // binary_linked_list_H
