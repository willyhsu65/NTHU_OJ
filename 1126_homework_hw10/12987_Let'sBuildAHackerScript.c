#include <stdio.h>
#include <string.h>
int x,y;
int flag = 0;
char s1[21];
char s2[21];
char ans[20][20];
void HackerScript(int,int ,int);
int main(void)
{
    scanf("%s",s1);
    scanf("%s",s2);
    x = strlen(s1);
    y = strlen(s2);
    HackerScript(0,0,0);
    //int n;
    //scanf("%d",&n);
    if(flag == 0)
        printf("What the hack!?");
    return 0;
}
void HackerScript(int step_s1,int step_s2,int hackscript)
{
    if(step_s1 == x && step_s2 == y)
    {
        if(flag == 0)
            flag = 1;
        for (int i = 0;i<hackscript-1;i++)
        {
            printf("%s ",ans[i]);
        }
        printf("%s\n",ans[hackscript-1]);
    }
    else if(s1[step_s1] == s2[step_s2])
    {
        HackerScript(step_s1+1,step_s2+1,hackscript);
    }
    else if(s2[step_s2] == '#')
    {
        for (int i = step_s1;i<x;i++)
        {
            for (int j = step_s1;j<=i;j++)
            {
                ans[hackscript][j-step_s1] = s1[j];
            }
            HackerScript(i+1,step_s2+1,hackscript+1);
            for (int j = step_s1;j<=i;j++)
            {
                ans[hackscript][j-step_s1] = '\0';
            }
        }
    }
}