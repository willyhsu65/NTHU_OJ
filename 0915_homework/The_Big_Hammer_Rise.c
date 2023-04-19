#include <stdio.h>

int main(void){
    int a,b,c,d;
    scanf("%d.%d %d.%d",&a,&b,&c,&d);
    int ans;
    a = a*100;
    c = c*100;
    ans = (a+b)*(c+d);
    printf("%d.%d",ans/10000,ans%10000);

}