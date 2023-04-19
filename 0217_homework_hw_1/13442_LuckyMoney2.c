#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    int order;
    struct node *left;
    struct node *right;
} Node;

typedef struct
{
    int data;
    int index;
} Age;

Node * input(int n,Age *age)
{
    Node *head = (Node *)malloc(sizeof(Node)*n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&head[i].data);
        age[i].data = head[i].data;
        head[i].order = i+1;
        age[i].index = i;
        if(i == n-1)
        {
            head[i].right = head;
            head->left = &head[i];
        }
        else
        {
            head[i].right = &head[i+1];
            head[i+1].left = &head[i];
        }
    }
    return head;
}

void Node_connect(Node *n1,Node *n2)
{
    n1->right = n2;
    n2->left = n1;
}

void move(Node *head,int ord,int steps,int dir,int n,Age *age)
{
    Node *tmp = &head[age[ord-1].index];
    if(dir == 1)
    {
        for (int i = 0;i < steps % (n-1);i++)
        {
            tmp = tmp->right;
        }
        Node_connect(head[age[ord-1].index].left,head[age[ord-1].index].right);
        Node_connect(&head[age[ord-1].index],tmp->right);
        Node_connect(tmp,&head[age[ord-1].index]);
    }
    else
    {
        for (int i = 0;i < steps %(n-1);i++)
            tmp = tmp->left;
        Node_connect(head[age[ord-1].index].left,head[age[ord-1].index].right);
        Node_connect(tmp->left,&head[age[ord-1].index]);
        Node_connect(&head[age[ord-1].index],tmp);
    }
    return;
}

void print(Node *head,int n,Age* age)
{
    Node *iter = &head[age[0].index];
    printf("%d",iter->data);
    iter = iter->right;
    while(iter != &head[age[0].index])
    {
        printf(" %d",iter->data);
        iter = iter->right;
    }
    printf("\n");
    return;
}

int compare(const void *a,const void *b)
{
    Age *a1 = (Age*)a;
    Age *a2 = (Age *)b;
    if(a1->data > a2->data)
        return 1;
    else if(a1->data < a2->data)
        return -1;
    else
    {
        if(a1->index > a2->index)
            return 1;
        else if(a1->index < a2->index)
            return -1;
        else return 0;
    }
}

int main(void)
{
    int n;
    int m;
    scanf("%d%d",&n,&m);
    Age *age = (Age *)malloc(sizeof(Age)*n);
    Node *head = input(n,age);
    qsort(age,n,sizeof(Age),compare);
    for (int i = 0;i<m;i++)
    {
        int a,k;
        char dir;
        int d;
        scanf("%d%d",&a,&k);
        getchar();
        scanf("%c",&dir);
        if(dir == 'R') d = 1;
        else d = 2;
        move(head,a,k,d,n,age);
    }
    print(head,n,age);
    free(head);
    return 0;
}

