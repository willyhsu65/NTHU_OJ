#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    if(n%2==0)
        printf("Stop drawing fake diamonds!");
    else {
        for (int i = 0;i<n/2+1;i++){
            for (int j = 0;j<n/2-i;j++){
                printf(" ");
            }
            for (int j = 0;j<1+i*2;j++){
                printf("*");
            }
            printf("\n");
        }
        for (int i = 0;i<n/2;i++){
            for (int j = 0;j<1+i;j++){
                printf(" ");
            }
            for (int j = 0;j<n/2-i*2+1;j++){
                printf("*");
            }
            printf("\n");
        }

    }




}36.4£¾£½¹Ã
