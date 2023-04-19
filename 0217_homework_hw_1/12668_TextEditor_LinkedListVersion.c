#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char alpha;
    struct node *next;
    struct node *pre;
} Node;

void Node_conc(Node *n1,Node *n2)
{
    n1->next = n2;
    n2->pre = n1;
}

Node * createNode(char c)
{
    Node *n = (Node *)malloc(sizeof(Node)*1);
    n->alpha = c;
    n->next = NULL;
    n->pre = NULL;
    return n;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    Node *head = NULL;
    Node *rear = NULL;
    for (int i = 0;i<t;i++)
    {
        int n;
        int len = 0;
        scanf("%d",&n);
        getchar();          
        Node *cursor;
        Node *head = createNode('\0');
        Node *rear;
        cursor = head;
        for (int i = 0;i<n;i++)
        {
            char c;

            scanf("%c",&c);
            if(c == 'L')
            {
                Node *tmp = cursor->pre;
                cursor = tmp;
            }
            else if(c == 'R')
            {
                cursor  = cursor->next;
            }
            else if(c == 'B')
            {
                Node *target;
                target = cursor;
                cursor = cursor->pre;
                if(target->next != NULL) Node_conc(cursor,target->next);
                else cursor->next = NULL;
                free(target);
                len--;
            }
            else
            {
                len++;
                Node *tmp = createNode(c);
                if(head->next == NULL)
                {
                    Node_conc(head,tmp);
                    cursor = head->next;
                }
                else
                {
                    if(cursor->next != NULL)
                    {
                        Node *n = cursor->next;
                        Node_conc(cursor,tmp);
                        Node_conc(tmp,n);
                    }
                    else Node_conc(cursor,tmp);
                    cursor = cursor->next;
                }
            }
        }
        while(head->next != NULL  && len > 0)
        {
            printf("%c",head->next->alpha);
            Node *tmp = head;
            head = head->next;
            free(tmp);
        }
        printf("\n");
    }
}
