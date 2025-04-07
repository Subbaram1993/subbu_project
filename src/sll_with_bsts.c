/****************************************************************/
/*	Name	:	Single Linked List of Binary Search 	*/
/*			Trees (BSTs).				*/
/*	Author	:	Subbaramaiah Chevuru			*/
/*								*/
/*								*/
/****************************************************************/


//==============================================================//
//			REVISION LOG				//
//==============================================================//
//								//
//	2025-04-07	-	Initial Draft of the Program	//
//								//
//								//
//								//
//==============================================================//


//Header files
#include <stdio.h>
#include <stdlib.h>

//Struct Declarations
typedef struct Tree{
    int data;
    struct Tree *left, *right;
}Tree;
 
typedef struct List{
    Tree *root;
    struct List *next;
}List; 

typedef struct SearchRes{
    int found;
    int node;
    int position;
}SearchRes;
 
//Global Variables
List *head=NULL, *q=NULL;
 

//List of Helper Functions.
List* create(Tree*);
List* create_LL_Tree();
void display(List*);
Tree* create_tree();
Tree* insert(Tree*, int);
void display_tree(Tree*);
void inorder(Tree*);
List* insert_ll(List*);
Tree* delete_data(Tree*, int);
List* delete_data_LL(List*);
SearchRes search_data(List*, int);
SearchRes search_tree(Tree*, int, int);


//Insert the Binary Search Tree into a Single Linked List
List* insert_ll(List *list)
{
    int data, pos,i=1;
    List *ins, *in=head, *last=NULL;
    ins = (List*)malloc(sizeof(List));
    if(ins==NULL){
        printf("\nMemory not allocated.\n");
        return NULL;
    }
    ins->root = NULL;
    printf("\nEnter the Data into the tree:\n");
    while(1){
        scanf("%d", &data);
        if(data < 0)break;
        ins->root = insert(ins->root, data);
    }
    printf("\nInserted in Tree:\n");
    printf("\nEnter the position to be insert:\n");
    scanf("%d", &pos);
    if(pos ==1 || head == NULL){
        ins->next = head;
        head = ins;
        return head;
    }
    while(i <= pos-1 && in != NULL){
        last = in;
        in = in->next;
        i++;
    }
    if(last==NULL){
        printf("\nPosition not found.\n");
        free(ins);
        return head;
    }
    ins->next = last->next;
    last->next = ins;
    return head;
}

 
//Insert the Data into  Binary Search Tree (BST)
Tree* insert(Tree *root, int data)
{
    if(root==NULL){
        Tree *t = (Tree*)malloc(sizeof(Tree));
        if(t==NULL){
            printf("\nMemory not allocated.\n");
            return NULL;
        }
        t->data = data;
        t->left = t->right = NULL;
        return t;
    }
    else if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
} 


//Create the Single Linked List having the BSTs..
List* create_LL_Tree()
{
    int data;
    char ch='y';
    printf("\nEnter the Trees for Linked List :\n");
    do{
        Tree *root = NULL;
        printf("\nEnter the Data into the tree:\n");
        while(1){
            scanf("%d", &data);
            if(data < 0)break;
            root = insert(root, data);
        }
        head = create(root);
        scanf("%c", &ch);
    }while(ch!='n');
    return head;
}


//Helper function to create the Single Linked List.
List* create(Tree *tree)
{
    List *p = (List*)malloc(sizeof(List));
    if(p==NULL){
        printf("\nMemory not allocated.\n");
        return NULL;
    }
    p->root = tree;
    p->next = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        q->next = p;
    }
    q = p;
    return head;
}

//Helper function to Inorder Traversal in BST.
void inorder(Tree *root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d -->", root->data);
    inorder(root->right);
}

//Displaying the BST
void display_tree(Tree* root)
{
    if(root==NULL){
        return;
   }
    inorder(root);
    printf("NULL\n");
}

//Helper function to display the Each Node having BST. 
void display(List *list)
{
    int i=1;
    if(list==NULL)
    {
        printf("\nList is Empty...!!!\n");
        return;
    }
    while(list != NULL){
        // printf("\nTree :%d Inorder Traversal: \n", i++);
        display_tree(list->root);
        list = list->next;
    }
}
 
//Helper function to Delete the Data in BST.
Tree* delete_data(Tree *tree, int ele)
{
    if(tree==NULL){
        return NULL;
    }
    if(ele < tree->data){
        tree->left = delete_data(tree->left, ele);
    }
    else if(ele > tree->data){
        tree->right = delete_data(tree->right, ele);
    }
    else{
        if(tree->left == NULL){
            Tree *temp = tree->right;
            free(tree);
            return temp;
        }
        else if(tree->right == NULL){
            Tree *temp = tree->left;
            free(tree);
            return temp;
        }
        Tree *temp = tree->right;
        while(temp->left !=NULL){
            temp = temp->left;
        }
        tree->data = temp->data;
        tree->right = delete_data(tree->right, ele);
    }
    return tree;
}

//Deleting the Data in the BST traversal through the Single Linked List.
List* delete_data_LL(List *list)
{
    int d, found=0;
    printf("\nEnter the data to be deleted :\n");
    scanf("%d", &d);
    if(list==NULL){
        printf("\nList is Empty....!!!\n");
        return NULL;
    }
    List *temp = list;
    while(temp != NULL){
        Tree *last = temp->root;
        temp->root = delete_data(temp->root, d);
        if(temp->root != last){
            found=1;
        }
        temp = temp->next;
    }
    if(!found){
        printf("\nElement not found .\n");
    }
    return list;
}


//Searching the Data in the BST.
SearchRes search_tree(Tree *root, int ser, int pos)
{
    SearchRes res = {0, -1, -1};
    if(root == NULL){
        return res;
    }
    if(root->data == ser){
        res.found = 1;
        res.position = pos;
        return res;
    }
    else if(ser < root->data){
        return search_tree(root->left, ser, pos+1);
    }
    else{
        return search_tree(root->right, ser, pos+1);
    }
}
 
//Helper function to search the data in BST by traversing through
//the Linked List.
SearchRes search_data(List* list, int ser)
{
    SearchRes res = {0,-1,-1};
    int i=1,j;
    if(list==NULL){
        printf("\nList is Empty....!!\n");
        return res;
    }
    while(list!=NULL){
        res = search_tree(list->root, ser,1);
        if(res.found){
            res.node = i;
            return res;
        }
        list = list->next;
        i++;
    }
    res.node =-1;
    return res;
}

//Freeing the allocated memory for BST by deleting them.
void free_tree(Tree* root)
{
    if(root==NULL){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}


//Freeing the allocated memory for Single Linked List by deleting them. 
void freeing_list(List* head)
{
    List *temp;
    printf("\nFreeing the List...!!!\n");
    while(head != NULL){
        temp = head;
        head = head->next;
        free_tree(temp->root);
        free(temp);
    }
}

//Main Starts Here
int main() {
    int d,ser;
    List *list = create_LL_Tree();
    display(list);
    list = insert_ll(list);
    printf("\nAfter inserting :\n");
    display(list);
    list = delete_data_LL(list);
    display(list);
    printf("\nEnter the element to search:\n");
    scanf("%d", &ser);
    SearchRes res = search_data(list, ser);
    if(res.found){
        printf("\nThe Element %d is found at position %d in %d node",ser, res.position, res.node);
    }
    else{
        printf("\nElement not found.\n");
    }
    freeing_list(list);
    return 0;
}
//Ends Here
