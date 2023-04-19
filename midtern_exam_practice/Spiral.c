#include <stdio.h>
#include <string.h>

char map[5001][5001];

int main(void){
    int n;
    int r[1000];
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        scanf("%d",&r[i]);
        }
    for (int i = 0;i<n;i++){
        int temp = r[i];
        int d = 0;
        int x = 0,y = 0;
        while(temp){
            for (int j = 0;j<temp;j++){
                map[x][y] = '#';
                if(j == temp-1){
                    x+=dir[(d+1)%4][0];
                    y+=dir[(d+1)%4][1];
                }
                else{
                    x+=dir[d][0];
                    y+=dir[d][1];
                }
            }
            d = (d+1)%4;
            temp--;
        }
        for (int j = 0;j<r[i];j++){
            for (int k = 0;k<r[i];k++){
                if(map[j][k] == '#')
                    printf("%c",map[j][k]);
                else
                    printf(" ");
            }
            printf("\n");
        }
        for (int j = 0;j<r[i];j++){
            for (int k = 0;k<r[i];k++){
                map[j][k] = '\0';
            }
        }

    }

}
