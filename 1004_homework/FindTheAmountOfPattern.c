#include <stdio.h>

int main(void){
    int n;
    int m;
    int om[20][20];
    int bm[20][20];
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            scanf("%d",&om[i][j]);
        }
    }
    scanf("%d",&m);
    for (int i = 0;i<m;i++){
        for (int j = 0;j<m;j++){
            scanf("%d",&bm[i][j]);
        }
    }
    int boolean = 1;
    int total = 0;
    for (int i = 0;i<n-m+1;i++){
        for (int j = 0;j<n-m+1;j++){
            for (int k = 0;k<m;k++){
                for (int l = 0;l<m;l++){
                   if(om[i+k][j+l] != bm[k][l]){
                        boolean = 0;
                        break;
                        }
                }
            }
            if(boolean==1)
                total++;
            boolean = 1;
        }
    }
    printf("%d",total);
    printf("\n");
}
