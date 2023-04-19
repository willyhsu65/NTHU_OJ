#include <stdio.h>

int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    int student[1000] = {0};
    int i = 1;
    while(i<=n){
        student[i-1] = i;
        i++;
    }
    i = 0;
    while(i<m){
        int a,b;
        scanf("%d %d",&a,&b);
        int temp;
        temp = student[a-1];
        student[a-1] = student[b-1];
        student[b-1] = temp;
        i++;
    }
    i = 1;
    while(i<=n){
        int j = 0;
        while(j<n){
            if(i == student[j]){
                printf("%d",j+1);
                break;
            }
            j++;
        }
        if(i<n)
            printf(" ");
        i++;
    }
    printf("\n");


    return 0;
}
