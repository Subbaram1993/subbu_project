#ifndef single_linked_list_H
#define single_linked_list_H

List* create_list();
void display(List *head);
List* insert(List* head);
int search(List* head);
List* middle_node(List* head);
List* delete_node(List* head);
List* reverse(List *head);
void create_loop(List* head, int p);
List* detect_loop(List *head);
void display_loop(List* loopnode);
List* loop(List *head);
void remove_loop(List *loopd);
void free_list(List* head);
void loop_func(List *loopd);
void sort(List* head);
void search_sort(List* list);
void info();

#endif // single_linked_list_H
