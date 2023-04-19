#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long length[55];

void solve(int k,long long left,long long right)
{
    //basic step
    if(k == 1)
    {
        char str[3] = {'O','u','Q'};
        for (int i = left;i <= right;i++)
        {
            printf("%c",str[i]);
        }
        return;
    }
    if(left > right)
        return;

    //recursive step
    if(left == 0)
    {
        printf("O");
        solve(k,left+1,right);
    }
    else if(left > 0 && right <= length[k-1]+1)
    {
        if(right == length[k-1]+1)
        {
            solve(k-1,left - 1,right - 2);
            printf("u");
        }
        else
            solve(k-1,left-1,right-1);
    }
    else if(left > 0 && left < length[k-1]+1 && right > length[k-1]+1)
    {
        solve(k-1,left-1,length[k-1]-1);
        printf("u");
        if(right == 2*length[k-1] + 2)
        {
            solve(k-1,0,right - (3 + length[k-1]));
            printf("Q");
        }
        else
            solve(k-1,0,right - (2+length[k-1]));
    }
    else if(left >= length[k-1]+1 && right > length[k-1]+1)
    {
        if(left == length[k-1]+1)
        {
            printf("u");
            left++;
        }
        if(right == 2*length[k-1] + 2)
        {    
            solve(k-1,left - (2+length[k-1]),right - (3+length[k-1]));
            printf("Q");
        }
        else
            solve(k-1,left - (2+length[k-1]),right - (2 + length[k-1]));
    }
}

int main(void)
{
    int k;
    long long left;
    long long right;
    length[1] = 3;
    for (int i = 2;i <= 50;i++)
    {
        length[i] = 2*length[i-1] + 3;
    }
    while(scanf("%d%lld%lld",&k,&left,&right) != EOF)
    {
        solve(k,left,right);
        printf("\n");
    }
}