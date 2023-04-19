#include <stdio.h>
#include <string.h>

char maze[1005][1005];
int flag[1005][1005];
int teleportx[1000000];
int teleporty[1000000];
int tel;
int tflag = 0;
int escape = 0;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int r,c;

void solve(int posx,int posy);

int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        scanf("%d%d",&r,&c);
        for (int j = 1;j<r+1;j++)
        {
            for (int k = 1;k<c+1;k++)
            {
                scanf(" %c",&maze[j][k]);
                if(maze[j][k] == 'T')
                {
                    teleportx[tel] = j;
                    teleporty[tel] = k;
                    tel++;
                }
            }
        }
        solve(1,1);
        if(tflag)
        {
            for (int i = 0;i<tel;i++)
            {
                solve(teleportx[i],teleporty[i]);
            }
        }

        if(escape)
            printf("Yes\n");
        else
            printf("No\n");
        escape = 0;
        tflag = 0;
        for (int j = 0;j<tel;j++)
        {
            teleportx[j] = 0;
            teleporty[j] = 0;
        }
        for (int j = 1;j<=r;j++)
        {
            for (int k = 1;k<=c;k++)
            {
                flag[j][k] = 0;
                maze[j][k] = '\0';
            }
        }
        tel = 0;
    }
}

void solve(int posx,int posy)
{
    if(escape)
        return;
    flag[posx][posy] = 1;
    if(posx == r && posy == c)
    {
        escape = 1;
        return;
    }
    if(maze[posx][posy] == 'T')
    {
        tflag = 1;
    }
    for (int i = 0;i<4;i++)
    {
        if(maze[posx+dir[i][0]][posy+dir[i][1]] != '#' && flag[posx+dir[i][0]][posy+dir[i][1]] == 0 && posx+dir[i][0] >= 1 && posx+dir[i][0] <= r && posy+dir[i][1] >= 1 && posy+dir[i][1] <= c)
        {
            solve(posx+dir[i][0],posy+dir[i][1]);
        }

    }
    return;
}
