#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    int data;
    struct _Node* next;
} Node;


void Push(Node** ptr_head, int x)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = x;
    if(*ptr_head != NULL)
        new->next = *ptr_head;
    else new->next = NULL;
    *ptr_head = new;
}
void Pop(Node** ptr_head)
{
    if(*ptr_head == NULL)
        return;
    Node *freenode = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(freenode);
}
void Reverse_List(Node** ptr_head)
{
    if(*ptr_head == NULL) return;   
    Node *new_head;
    new_head = NULL;
    while((*ptr_head)->next != NULL)
    {
        Node *tmp = (*ptr_head)->next;
        (*ptr_head)->next = new_head;
        new_head = (*ptr_head);
        *ptr_head = tmp;
    }
    (*ptr_head)->next = new_head;
}

//main
void Print_List(Node* head);
void Delete_List(Node* head);

int main(){
    char op[10];
    Node* head = NULL;
    while( ~scanf("%s", op) ){
        if( strcmp(op, "push") == 0 ){
            int x;
            scanf("%d", &x);
            Push(&head, x);
        }
        if( strcmp(op, "pop") == 0 ){
            Pop(&head);
        }
        if( strcmp(op, "reverse") == 0 ){
            Reverse_List(&head);
        }
        if( strcmp(op, "print") == 0 ){
            Print_List(head);
        }
    }

    Delete_List(head);
    head = NULL;

    return 0;
}
void Print_List(Node* head){
    if( head == NULL ){
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if( head->next != NULL ) printf(" -> ");
    Print_List(head->next);
}

void Delete_List(Node* head){
    if( head == NULL ) return;
    Delete_List(head->next);
    free(head);
}