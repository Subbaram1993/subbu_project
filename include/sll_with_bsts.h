#ifndef sll_with_bsts_H
#define sll_with_bsts_H

List* insert_ll(List *list);
Tree* insert(Tree *root, int data);
List* create_LL_Tree();
List* create(Tree *tree);
void inorder(Tree *root);
void display_tree(Tree* root);
void display(List *list);
Tree* delete_data(Tree *tree, int ele);
List* delete_data_LL(List *list);
SearchRes search_tree(Tree *root, int ser, int pos);
SearchRes search_data(List* list, int ser);
void free_tree(Tree* root);
void freeing_list(List* head);

#endif // sll_with_bsts_H
