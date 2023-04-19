#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char f0[2020];
char f1[2020];
long long int len[100];

char solve(int n,long long int k)
{
    if(n == 0) return f0[k];
    if(n == 1) return f1[k];
    if(k >= len[n-2])
        return solve(n-1,k-len[n-2]);
    else
        return solve(n-2,k);
}
int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i = 0;i<t;i++)
    {
        int n;
        long long int k;
        scanf("%s %s",f0,f1);
        scanf("%d %lld",&n,&k);
        len[0] = strlen(f0);
        len[1] = strlen(f1);
        for (int j = 2;j<=n;j++)
        {
            len[j] = len[j-1] + len[j-2];
        }
        char c = solve(n,k);
        printf("%c\n",c);
    }
}