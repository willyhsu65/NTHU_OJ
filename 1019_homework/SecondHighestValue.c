#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int n;
    int arr[1000];
    int max = 0;
    int secmax = 0;
    //declaration

    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0;i<n;i++){
        if(arr[i]>max){
            secmax = max;
            max = arr[i];
        }
        else if(arr[i]>secmax){
            secmax = arr[i];
        }
        if(i == n-1)
            printf("%d",secmax);
        else
            printf("%d ",secmax);
    }
    printf("\n");
    //input

    return 0;
}
