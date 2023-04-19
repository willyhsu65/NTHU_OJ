#include <stdio.h>
long long total = 0;
long long Sierpinski(int k){
    if(k == 1)
        return 1;
    if(k == 2)
        return 9;
    return Sierpinski(k-1)*9 - Sierpinski(k-2)*8;
}

int main(void){
    int k;
    scanf("%d",&k);
    int ans = Sierpinski(k);
    printf("%d\n",ans);
}
