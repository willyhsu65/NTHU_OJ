#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_LEN 100
int N = 0;
typedef struct{
    int score;
    char* name;
} Node;

int cmp(const Node *a,const Node *b)
{
    if(a->score > b->score) return 1;
    if(a->score < b->score) return -1;
    int cs = strcmp(a->name,b->name);
    if(cs > 0) return -1;
    if(cs < 0) return 1;
    return 0;
}

void Insert( Node** Table, int N, int score, char* name )
{
    Node *a = (Node *)malloc(sizeof(Node)*1);
    char *n = (char *)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(n,name);
    a->name = n;
    a->score = score;
    Table[N] = a;
    for (int i = N-1;i >= 0;i--)
    {
        if(cmp(Table[i],Table[i+1]) == -1)
        {
            Node *tmp = Table[i];
            Table[i] = Table[i+1];
            Table[i+1] = tmp;
        }
        else break;
    }
}
void Delete( Node** Table, int N, char* name )
{
    for (int i = 0;i<N;i++)
    {
        if(strcmp(Table[i]->name,name) == 0)
        {
            free(Table[i]->name);
            free(Table[i]);
            for (int j = i;j<N-1;j++)
            {
                Table[j] = Table[j+1];
            }
            Table[N-1] = NULL;
            return;
        }
    }
}
int* Top( Node** Table, int N, int x)
{
    int *idx = (int *)malloc(sizeof(int)*x);
    for (int i = 0;i<x;i++)
    {
        idx[i] = i;
    }
    return idx;
}

Node* Table[MAX_SIZE];


int main(){
    for(int i=0; i<MAX_SIZE; i++)
        Table[i] = NULL;

    int K;
    scanf("%d", &K);

    char op[10];

    while( K-- ){
        // printf("K: %d\n", K);
        scanf("%s", op);
        if( strcmp(op, "INSERT" ) == 0 ){
            int score;
            char name[MAX_LEN+1];
            scanf("%d %s", &score, name );

            Insert(Table, N, score, name );
            N++;
        }
        else if( strcmp(op, "DELETE" ) == 0 ){
            char name[MAX_LEN+1];
            scanf("%s", name);

            Delete(Table, N, name );
            N--;
        }
        else if( strcmp(op, "TOP" ) == 0 ){
            int x;
            scanf("%d", &x);

            int* idxs = Top(Table, N, x);
            printf("Top %d:\n", x);
            for(int i=0; i<x; i++){
                printf("%d %s\n", Table[idxs[i]]->score, Table[idxs[i]]->name );
            }
            free( idxs );
        }
    }
    for(int i=0; i<MAX_SIZE; i++){
        if( Table[i] != NULL ){
            free(Table[i]->name);
            free(Table[i]);
            Table[i] = NULL;
        }
    }

    return 0;
}