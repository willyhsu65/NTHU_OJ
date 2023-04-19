#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 101
#define M 10001

char *student[N];
char op[15];
char s[105];
int len[105];

void Add(int n);
void Delete(int n,int k);
void swap(int s1,int s2);
void longest(int n);
void All(int n);

int main(void)
{
    int t,m;
    scanf("%d %d",&t,&m);
    for (int i = 0;i<105;i++)
    {
        len[i] = 0;
        student[i] = (char *)malloc(sizeof(char)*1);
        student[i][0] = '\0';
    }
    for (int i = 0;i<m;i++)
    {
        scanf("%s",op);
        if(strcmp(op,"add") == 0)
        {
            int n;
            scanf("%d %s",&n,s);
            Add(n);
        }
        else if(strcmp(op,"delete") == 0)
        {
            int n,k;
            scanf("%d %d",&n,&k);
            Delete(n,k);
        }
        else if(strcmp(op,"swap") == 0)
        {
            int n1,n2;
            scanf("%d%d",&n1,&n2);
            swap(n1,n2);
        }
        else if(strcmp(op,"longest") == 0)
        {
            longest(t);
        }
        else if(strcmp(op,"all") == 0)
        {
            All(t);
        }
    }
}

void Add(int n)
{
    char *tmp = (char *)malloc(sizeof(char)*(len[n]+1));
    strcpy(tmp,student[n]);
    free(student[n]);
    len[n] += strlen(s);
    student[n] = (char *)malloc(sizeof(char)*(len[n]+1));
    strcpy(student[n],tmp);
    strcat(student[n],s);
    free(tmp);
}
void Delete(int n,int k)
{
    if(k >= len[n])
    {
        len[n] = 0;
        free(student[n]);
        student[n] = (char *)malloc(sizeof(char)*1);
        student[n][0] = '\0';
    }
    else
    {
        len[n] -= k;
        char *tmp = (char *)malloc(sizeof(char)*(len[n]+1));
        strncpy(tmp,student[n],len[n]);
        tmp[len[n]] = '\0';
        free(student[n]);
        student[n] = tmp;
    }
}
void swap(int s1,int s2)
{
    char *tmp;
    tmp = student[s1];
    student[s1] = student[s2];
    student[s2] = tmp;
    int temp = len[s1];
    len[s1] = len[s2];
    len[s2] = temp;
}
void longest(int n)
{
    int max = 0,id = 0;
    for (int i = 1;i<=n;i++)
    {
        if(max < len[i])
        {
            max = len[i];
            id = i;
        }
    }
    printf("%d %s\n",max,student[id]);
}
void All(int n)
{
    for (int i = 1;i<=n;i++)
    {
        printf("%s\n",student[i]);
    }
}