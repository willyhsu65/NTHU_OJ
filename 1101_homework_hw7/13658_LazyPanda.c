#include <stdio.h>
#include <limits.h>
#include <strings.h>
char map[1001][1001];
int min = INT_MAX;
int s = 0;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int route[1000000];
int smaller(int a,int b){
    if(a>b)
        return b;
    return a;
}
void step(int pos_i,int pos_j){
    if(map[pos_i][pos_j]!='.'||map[pos_i][pos_j]!='M'){
        return -1;
    }
    if(map[pos_i][pos_j] == '.'){
        s++;
    }

    for (int i = 0;i<4;i++){
        return step(pos_i+dir[i][0],pos_j+dir[i][1]);
    }
}

int main(void){
    int m,n;
    int pos_i,pos_j;
    scanf("%d%d",&m,&n);
    for (int i = 1;i<=m;i++){
        for (int j = 1;j<=n;j++){
            scanf(" %c",&map[i][j]);
            if(map[i][j] == 'S'){
                pos_i = i;
                pos_j = y;
            }
        }
    }
    int ans = step(pos_i,pos_j);
    printf("%d\n",ans);
}
