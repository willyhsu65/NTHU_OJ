#include <stdio.h>
#include <string.h>

int getlen(long long int b)
{
    int digit = 0;
    while(b)
    {
        b /= 10;
        digit++;
    }
    return digit;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    int len = getlen(b) - 1;
    long long int ans = len * a;
    printf("%lld\n",ans);
    }
}