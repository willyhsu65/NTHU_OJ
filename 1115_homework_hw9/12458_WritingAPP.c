#include <stdio.h>
#include <string.h>
#include <limits.h>
int delete_map[1001][1001];
char str[1001];
int check_palindrome(int l,int r);
int min(int,int);
int main(void)
{
    int length;
    int n;
    scanf("%d%d",&length,&n);
    for (int i = 0;i < length+1;i ++ )
    {
        for (int j = 0;j< length+1;j++)
        {
            delete_map[i][j] = INT_MAX;
        }
    }
    scanf("%s",str);
    int min = check_palindrome(0,length-1);
    if(min > n)
    {
        printf("No\n");
    }
    else if(min <= n)
    {
        printf("Yes\n");
    }
}
int check_palindrome(int l,int r)
{   
    if(delete_map[l][r] != INT_MAX)
    {
        return delete_map[l][r];
    }
    else
    {
        if(l >= r)
        {   
            delete_map[l][r] = 0;
            return 0;
        }
        if(str[l] == str[r])
        {   
            delete_map[l][r] = check_palindrome(l+1,r-1);
            return delete_map[l][r];
        }
        else if(str[l] != str[r])
        {
            delete_map[l][r] = min(check_palindrome(l+1,r)+1,check_palindrome(l,r-1)+1);
            return delete_map[l][r];
        }
    }
}
int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
