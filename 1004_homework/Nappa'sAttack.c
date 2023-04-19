#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int temp = 0;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n-i-1;j++){
            printf(" ");
        }
        for (int j = 0;j<i+1;j++){
            temp++;
            printf("%d",temp);
        }
        for (int j = 0;j<i+1;j++){
            temp--;
            if(temp==0)
                break;
            printf("%d",temp);
        }
        printf("\n");
    }
}
