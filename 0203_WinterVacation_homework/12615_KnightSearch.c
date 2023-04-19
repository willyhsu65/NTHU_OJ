#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int n,int x,int y,int id);
char str[20] = {'I','C','P','C','A','S','I','A','S','G','\0'};
char land[105][105];
int posx[10000];
int posy[10000];
int num;
int flag = 0;
int dir[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,-2},{-1,-2},{1,2},{-1,2}};

int main(void)
{
    int n; 
    scanf("%d",&n);
    getchar();
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++)
        {
            scanf("%c",&land[i][j]);
            if(land[i][j] == 'I')
            {
                posx[num] = i;
                posy[num] = j;
                num++;
            }
        }
    }
    for (int i = 0;i<num;i++)
    {
        if(flag)
            break;
        solve(n,posx[i],posy[i],0);
    }
    if(flag == 0)
        printf("NO\n");
}

void solve(int n,int x,int y,int id)
{
    if(flag)
        return;
    if(id >= 9)
    {
        flag = 1;
        printf("YES\n");
        return;
    }
    for (int i = 0;i<8;i++)
    {
        if(flag)
            return;
        if(x + dir[i][0] < n && x + dir[i][0] >= 0 && y + dir[i][1] < n && y + dir[i][1] >= 0 && land[x + dir[i][0]][y + dir[i][1]] == str[id+1])
        {
            solve(n,x + dir[i][0],y + dir[i][1],id+1);
        }
    }
    return;
}
