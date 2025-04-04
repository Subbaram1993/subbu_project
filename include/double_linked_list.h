#ifndef double_linked_list_H
#define double_linked_list_H

Double* create_list();
void display(Double *head);
Double* insert(Double *head);
void free_list(Double* head);
Double* reverse(Double *head);
int search(Double *head, int ele);
void sort(Double *head);
void search_sort(Double *head);
Double* middle_node(Double *head);
Double* delete_node(Double *head);
void info();
int main() ;

#endif // double_linked_list_H
