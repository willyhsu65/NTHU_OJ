#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number, age;
    struct _Node* prev;
    struct _Node* next;
}Node;
typedef struct age
{
    int ord;
    int data;
} Age;

int compare(const void *a,const void *b)
{
    Age *a1 = (Age *)a;
    Age *a2 = (Age *)b;
    if(a1->data > a2->data) return 1;
    else if(a1->data < a2->data) return -1;
    else
    {
        if(a1->ord > a2->ord) return 1;
        else if(a1->ord < a2->ord) return -1;
        else return 0;
    }
}

Node* head;
Age *age;
Node* createList(int n)
{
    Node *node = (Node *)malloc(sizeof(Node)*n);
    age = (Age *)malloc(sizeof(Age)*n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&head[i].age);
        age[i].data = head[i].age;
        head[i].number = i+1;
        age[i].ord = i;
        if(i > 0)
        {
            node[i].prev = &node[i-1];
            node[i-1].next = &node[i];
        }
    }
    node[n-1].next = node;
    node->prev = &node[n-1];
    qsort(age,n,sizeof(Age),compare);
}
Node* solve(int n, int m)
{
    for (int i = 0;i < m;i++)
    {
        int th,step;
        char c;
        Node *iter = NULL;
        scanf("%d%d %c",&th,&step,&c);
        if(c == 'R')
        {
            iter = &head[age[th].ord];
            for (int j = 0;j < step % (n-1);j++)
            {
                iter = iter->next;
            }
            head[age[th].ord].prev->next = head[age[th].ord].next;
            head[age[th].ord].next->prev = head[age[th].ord].prev;
            head[age[th].ord].next = iter->next;
            iter->next->prev = head[age[th].ord].next;
            head[age[th].ord].prev = iter;
            iter->next = &head[age[th].ord];
        }
        else
        {
            iter = &head[age[th].ord];
            for (int j = 0;j<step % (n-1);j++)
            {
                iter = iter->prev;
            }
            
        }
    }
}


int main(){

    int n, k;

    scanf("%d%d", &n, &k);
    head = createList(n);
    Node *p = solve(n, k);
    for(int i = 0; i < n; i ++){
        printf("%d ", p -> age);
        p = p -> next;
    }
    printf("\n");
    return 0;
}