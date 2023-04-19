#include <stdio.h>

int main(void){
    int a;
    scanf("%d",&a);
    if(a>=1200){
        printf("%02d:%02d p.m.",a/100-12,a%100);
    }
    if(a<1200){
        printf("%02d:%02d a.m.",a/100,a%100);
    }
}
