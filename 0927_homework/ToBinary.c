#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int bit[32] = {0};
    int i = 0;
    if(n==0)
        printf("%d",n);
    while(n){
        bit[31-i] = n%2;
        n = n/2;
        i++;
    }
    i = 0;
    int temp = 0;
    while(i<32){
        if(bit[i]==0&&temp == 0){
            i++;
            continue;
        }
        if(bit[i]==1&&temp == 0)
            temp = 1;
        printf("%d",bit[i]);
        i++;
    }
    printf("\n");
}
