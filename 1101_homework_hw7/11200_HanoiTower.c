#include <stdio.h>

void Hanoi(int n,char from,char to,char buffer){
    if(n==1){
        printf("%d\n",n);
        return;
    }
    Hanoi(n-1,from,buffer,to);
    printf("%d\n",n);
    Hanoi(n-1,buffer,to,from);
}

int main(void){
    int n;
    scanf("%d",&n);
    Hanoi(n,'A','B','C');
}
