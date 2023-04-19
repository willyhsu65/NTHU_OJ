#include <stdio.h>
#include <limits.h>

char maze[501][501];
int curstep = 0;
int stepx[501];
int stepy[501];
int maze_route[501][501];
int maze_step[501][501];
int flag[501][501] = {0};
int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
int ans[1000000];
int c,r;
int lstep = INT_MAX;
void escape(int posx,int posy,int step)
{
    if(maze[posx][posy] == 'F' ||(maze_step[posx][posy] != 0 && step >= maze_route[posx][posy])){
        step += maze_step[posx][posy];
        if(step < lstep)
        {
            lstep = step;
            for (int i = 1;i<= step;i++)
            {
                maze_route[stepx[i]][stepy[i]] = step;
                maze_step[stepx[i]][stepy[i]] = step - i;
                stepx[i] = 0;
                stepy[i] = 0;
            }
        }
        flag[posx][posy] = 0;
        return;
    }
    flag[posx][posy] = 1;
    stepx[step] = posx;
    stepy[step] = posy;
    for (int i = 0;i<4;i++){
        if(maze[posx+dir[i][0]][posy+dir[i][1]] !='#' && posx+dir[i][0]<r && posx+dir[i][0]>=0 && posy+dir[i][1]<c && posy+dir[i][1]>=0 && flag[posx+dir[i][0]][posy+dir[i][1]] == 0){
            escape(posx+dir[i][0],posy+dir[i][1],step+1);
        }
    }
    flag[posx][posy] = 0;
}

int main(void)
{
    int n;
    int posx,posy;
    scanf("%d",&n);
    for (int i = 0;i<501;i++)
    {
        for (int j = 0;j<501;j++)
        {
            maze_step[i][j] = 0;
        }
    }
    for (int i = 0;i<n;i++)
    {
        scanf("%d%d",&r,&c);
        for (int j = 0;j<r;j++)
        {
            for (int k = 0;k<c;k++)
            {
                scanf(" %c",&maze[j][k]);
                if(maze[j][k] == 'S')
                {
                    posx = j;
                    posy = k;
                }
            }
        }
        escape(posx,posy,0);
        if(lstep == INT_MAX)
            printf("-1\n");
        else
            printf("%d\n",lstep);
        lstep = INT_MAX;
    }

    return 0;
}
