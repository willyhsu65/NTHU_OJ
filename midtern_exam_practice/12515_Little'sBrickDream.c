#include <stdio.h>

int height[10000001];
int confort_level[10000001];
int ans[10000001];

int main(void)
{
    int n,x;
    int num = 0;
    int flag = 0;
    scanf("%d%d",&n,&x);
    int j;
    for (int i = 1;i<=n;i++)
    {
        scanf("%d",&height[i]);
        for (j = i-1;j>=1;)
        {
            if(height[i] > height[j])
            {
                j = j-confort_level[j] - 1;
            }
            else
                break;
        }
        confort_level[i] = i - j -1;
        if(confort_level[i] == x)
        {
            if(flag == 0)
            {
                flag = 1;
                printf("%d",i);
            }
            else
                printf(" %d",i);
        }
    }
    if(flag == 0)
        printf("ouo");
    printf("\n");
}
