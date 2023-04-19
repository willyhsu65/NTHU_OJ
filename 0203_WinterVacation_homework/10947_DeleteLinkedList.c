#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data)
{
    Node *target = NULL;
    Node *pre = *nd;
    for (int i = 1;i < data-1;i++)
    {
        if(pre->next == NULL) return;
        pre = pre->next;
    }

    if(pre->next == NULL) return;
    else if(data == 1)
    {
        Node *tmp = *nd;
        *nd = (*nd)->next;
        free(tmp);
    }
    else
    {
        Node *target = pre->next;
        Node *tmp = target->next;
        free(target);
        pre->next = tmp;
    }
}

Node* createList()
{
    Node *head = NULL;
    Node *curr = NULL;
    int n;
    scanf("%d",&n);
    if(n == -1) return NULL;
    else
    {
        Node *tmp = (Node *)malloc(sizeof(Node)*1);
        tmp->data = n;
        head = tmp;
        curr = tmp;
    }
    while(1)
    {
        scanf("%d",&n);
        if(n == -1) break;
        else
        {
            Node* tmp = (Node *)malloc(sizeof(Node)*1);
            tmp->data = n;
            curr->next = tmp;
            curr = tmp;
        }
    }
    curr->next = NULL;
    return head;
}

void printList(Node *head){
    Node *temp;
    for(temp = head; temp!=NULL; temp=temp->next) {
        printf("%d ", temp->data);
    }
}

void freeList(Node *head){
    Node *temp;
    for(temp=head; temp!=NULL; temp=head){
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head;
    int data;

    head = createList();

    while(1){
        scanf("%d", &data);
        if(data>-1){
            deleteNode(&head,data);
            printList(head);
            printf("\n");
        }else break;

    }

    printList(head);
    freeList(head);
    return 0;
}