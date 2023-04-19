#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b)
{
    const int* a1 = (const int *)a;
    const int* a2 = (const int *)b;
    if(*a1 > *a2)
        return 1;
    else if(*a2 > *a1)
        return 0;
}

int main(void)
{
    int n;
    int mindist;
    scanf("%d",&n);
    int *x = (int *)malloc(sizeof(int)*(n+1));
    for (int i = 0;i<n+1;i++)
    {
        scanf("%d",&x[i]);
    }
    qsort(x,n+1,sizeof(int),compare);
    mindist = x[n] - x[0];
    printf("%d\n",mindist*2);
}