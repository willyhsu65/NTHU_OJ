#include <stdio.h>
long long a,b,c,d;
long long ff(long long n);
long long gf(long long n);
long long ff(long long n){
    if(n == 0)
        return a;
    else if(n == 1)
        return b;
    else if(n%2 == 0 && n != 0){
        return ff(n-1) + gf(n/2);
    }
    else
        return ff(n-1) + gf(n-2);
}
long long gf(long long n){
    if(n == 0)
        return c;
    else if(n == 1)
        return d;
    else if(n%3 == 0 && n != 0 )
        return gf(n-1) + ff(n/3);
    else
        return gf(n-1) + ff(n-2);
}
int main(void){
    int n;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
    printf("%lld %lld\n",ff(n),gf(n));
}

