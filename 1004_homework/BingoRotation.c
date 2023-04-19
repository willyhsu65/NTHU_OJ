#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int bingo[100][100];
    int angle;
    int ans[100][100];
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            scanf("%d",&bingo[i][j]);
        }
    }
    scanf("%d",&angle);
    for (int i = 0;i<angle/90;i++){
        for (int j = 0;j<n;j++){
            for (int k = 0;k<n;k++){
                ans[abs(k-n+1)][j] = bingo[j][k];
            }
        }
        for (int j = 0;j<n;j++){
            for (int k = 0;k<n;k++){
                bingo[j][k] = ans[j][k];
            }
        }
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            if(j==n-1)
                printf("%d",bingo[i][j]);
            else
                printf("%d ",bingo[i][j]);
        }
        printf("\n");
    }
}
