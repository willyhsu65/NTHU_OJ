#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList()
{
    Node *node = (Node*)malloc(sizeof(Node)*1);
    node->next = NULL;
    int n;
    scanf("%d:",&n);
    node->size = n;
    node->data = (int *)malloc(sizeof(int)*n);
    for (int i = 0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        node->data[i] = a;
    }
    return node;
}
void PrintList(Node* head)
{
    Node *iter = head->next;
    while(iter != NULL)
    {
        for (int i = 0;i<iter->size;i++)
        {
            if(i == iter->size-1)
                printf("%d\n",iter->data[i]);
            else
                printf("%d ",iter->data[i]);
        }
        iter = iter->next;
    }
}
void Merge(Node* head,int id1,int id2)
{
    if(id1 == id2) return;
    Node *tmp1 = head;
    Node *tmp2 = head;
    Node *pre;
    if(id1 == 1)
        pre = head;
    
    for (int i = 0;i<id1;i++)
    {
        tmp1 = tmp1->next;
        if(i == id1-2)
            pre = tmp1;
    }
    for (int j = 0;j<id2;j++)
        tmp2 = tmp2->next;
    if(tmp1->next != NULL)
        pre->next = tmp1->next;
    else
        pre->next = NULL;
    int newsize = tmp1->size + tmp2->size;
    int *newdata = (int *)malloc(sizeof(int)*newsize);
    for (int i = 0;i < newsize;i++)
    {
        if(i > tmp2->size - 1)
        {
            newdata[i] = tmp1->data[i - tmp2->size];
        }
        else
        {
            newdata[i] = tmp2->data[i];
        }
    }
    tmp2->size = newsize;
    free(tmp2->data);
    tmp2->data = newdata;
    free(tmp1->data);
    free(tmp1);
}
void Cut(Node* head,int stackid,int numid)
{
    Node *new = (Node *)malloc(sizeof(Node)*1);
    Node *stack = head;
    for (int i = 0;i<stackid;i++)
    {
        stack = stack->next;
    }
    new->data = (int *)malloc(sizeof(int)*(stack->size - numid));
    int *stackdata = (int *)malloc(sizeof(int)*numid);
    for (int i = 0;i<stack->size;i++)
    {
        if(i < numid)
            stackdata[i] = stack->data[i];
        else
            new->data[i - numid] = stack->data[i];
    }
    free(stack->data);
    stack->data = stackdata;
    new->next = stack->next;
    stack->next = new;
    new->size = stack->size - numid;
    stack->size = numid;
}

int main(){
    Node* dummy_head;
    Node* tail;

    dummy_head = (Node*) malloc( sizeof(Node) );
    dummy_head->data = NULL;
    dummy_head->size = -1;

    tail = dummy_head;

    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        tail->next = ReadOneList();
        tail = tail->next;   
    }
    char act[10];
    int x, y;
    for(int i=0; i<M; i++){
        scanf("%s %d %d", act, &x, &y);
        if( act[0] == 'M' ){
            Merge(dummy_head, x, y);
        }
        else{
            Cut(dummy_head, x, y);
        }
    }
    PrintList(dummy_head);
    return 0;
}