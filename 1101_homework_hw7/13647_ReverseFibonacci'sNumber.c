#include <stdio.h>
int a,b;
int ReverseFib(int n){
    if(n == 0)
        return a;
    if(n == 1)
        return b;
    return ReverseFib(n-2) - ReverseFib(n-1);
}
int main(void){
    int n;
    scanf("%d%d%d",&a,&b,&n);
    int ans = ReverseFib(n);
    printf("%d\n",ans);


}
