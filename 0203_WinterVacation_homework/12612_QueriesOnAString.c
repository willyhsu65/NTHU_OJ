#include <stdio.h>
#include <string.h>

char str[10005];
char tmp[10005];


int main(void)
{
    int n;
    int left;
    int right;
    int shift;

    scanf("%s",str);
    scanf("%d",&n);
    int len = strlen(str);
    for (int i = 0;i<n;i++)
    {
        scanf("%d%d%d",&left,&right,&shift);
        if(left == right)
            continue;
        shift = shift % (right - left + 1);
        for (int j = left-1;j<=right-1;j++)
        {
            if(j + shift <= right-1)
                tmp[j+shift] = str[j];
            else if(j + shift > right-1)
            {
                tmp[j + shift - right + left-1 ] = str[j];
            }
        }
        for (int j = left-1;j <= right-1;j ++)
        {
            str[j] = tmp[j];
        }
    }
    printf("%s\n",str);
}