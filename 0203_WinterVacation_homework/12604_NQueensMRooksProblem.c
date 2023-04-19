#include <stdio.h>
#include <string.h>

int n,m,size,ans;
int chessboard[10][10];

void dfs(int row,int q,int r)
{
    if(row == size)
    {
        ans++;
        return;
    }
    for (int col = 0;col < size;col++)
    {
        if(chessboard[row][col]) continue;
        for (int i = row + 1;i < size;i++)
            chessboard[i][col]++;
        if(q < n)
        {
            int flag = 1;
            for (int i = row - 1,j = col - 1;i >= 0 && j >= 0;i--,j--)
            {
                if(chessboard[i][j] == -1)
                    flag = 0;
            }
            for (int i = row - 1,j = col + 1;i >= 0 && j < size;i--,j++)
            {
                if(chessboard[i][j] == -1)
                    flag = 0;
            }
            if(flag)
            {
                for(int i = row + 1,j = col - 1;i < size && j >= 0;i++,j--)
                    chessboard[i][j]++;
                for (int i = row + 1,j = col + 1;i < size && j <size;i++,j++)
                    chessboard[i][j]++;
                dfs(row+1,q+1,r);
                for(int i = row + 1,j = col - 1;i < size && j >= 0;i++,j--)
                    chessboard[i][j]--;
                for (int i = row + 1,j = col + 1;i < size && j <size;i++,j++)
                    chessboard[i][j]--;
            }
        }
        if(r < m)
        {
            chessboard[row][col] = -1;
            dfs(row+1,q,r+1);
            chessboard[row][col] = 0;
        }
        for (int i = row+1;i<size;i++)
            chessboard[i][col]--;
    }
}

int main(void)
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        size = n + m;
        ans = 0;
        memset(chessboard,0,sizeof(chessboard));
        dfs(0,0,0);
        printf("%d\n",ans);
    }
}