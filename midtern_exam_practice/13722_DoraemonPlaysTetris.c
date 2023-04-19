#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 21

int dp[N][N][N][N][N][N];

int solve(int ti,int a,int b,int c,int d,int e);
int max(int a,int b);

int sqlen;
int tq[N];
int t;

int main(void)
{
    int n;

    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        scanf("%d%d",&t,&sqlen);

        for (int j = 0;j<t;j++)
        {
            scanf("%d",&tq[j]);
        }
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,0,0,0);
        if(ans == t+1)
            printf("Win\n");
        else
            printf("Lose at %d\n",ans);
    }
}

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int solve(int ti,int a,int b,int c,int d,int e)
{
    if(dp[ti][a][b][c][d][e] != -1)
        return dp[ti][a][b][c][d][e];
    int value = ti+1;
    int tmp;
    if(ti >= t)
        return dp[ti][a][b][c][d][e] = t+1;
    switch (tq[ti])
    {
    case 1:
        if(a+4 <= sqlen) value = max(value,solve(ti+1,a+4,b,c,d,e));
        if(b+4 <= sqlen) value = max(value,solve(ti+1,a,b+4,c,d,e));
        if(c+4 <= sqlen) value = max(value,solve(ti+1,a,b,c+4,d,e));
        if(d+4 <= sqlen) value = max(value,solve(ti+1,a,b,c,d+4,e));
        if(e+4 <= sqlen) value = max(value,solve(ti+1,a,b,c,d,e+4));

        tmp = max(max(a,b),max(c,d));
        if(tmp+1 <= sqlen) value = max(value,solve(ti+1,tmp+1,tmp+1,tmp+1,tmp+1,e));
        tmp = max(max(b,c),max(d,e));
        if(tmp+1 <= sqlen) value = max(value,solve(ti+1,a,tmp+1,tmp+1,tmp+1,tmp+1));
        break;
    case 2:
        tmp = max(a,b);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,tmp+2,tmp+2,c,d,e));
        tmp = max(b,c);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,tmp+2,tmp+2,d,e));
        tmp = max(c,d);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,b,tmp+2,tmp+2,e));
        tmp = max(d,e);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,b,c,tmp+2,tmp+2));
        break;
    case 3:
        tmp = max(max(a,b+1),c);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,tmp+1,tmp+2,tmp+1,d,e));
        tmp = max(max(b,c+1),d);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,tmp+1,tmp+2,tmp+1,e));
        tmp = max(max(c,d+1),e);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,b,tmp+1,tmp+2,tmp+1));
        break;
    default:
        tmp = max(max(a+1,b+1),c);
        if(tmp+1 <= sqlen) value = max(value,solve(ti+1,tmp,tmp+1,tmp+1,d,e));
        tmp = max(max(b+1,c+1),d);
        if(tmp+1 <= sqlen) value = max(value,solve(ti+1,a,tmp,tmp+1,tmp+1,e));
        tmp = max(max(c+1,d+1),e);
        if(tmp+1 <= sqlen) value = max(value,solve(ti+1,a,b,tmp,tmp+1,tmp+1));

        tmp = max(a,b+1);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,tmp+2,tmp+1,c,d,e));
        tmp = max(b,c+1);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,tmp+2,tmp+1,d,e));
        tmp = max(c,d+1);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,b,tmp+2,tmp+1,e));
        tmp = max(d,e+1);
        if(tmp+2 <= sqlen) value = max(value,solve(ti+1,a,b,c,tmp+2,tmp+1));
        break;
    }

    return dp[ti][a][b][c][d][e] = value;
}
