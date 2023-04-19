#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char str[10000001];

int main(void)
{
    int n  =0;
    char key[21];
    char *token;
    char s[12] = " -/:()[],.\n";
    scanf("%s",key);
    int len = strlen(key);
    while((fgets(str,10000001,stdin)) != NULL)
    {
        token = strtok(str,s);
        while(token != NULL)
        {
            int flag = 1;
            if(len != strlen(token))
            {
                flag = 0;
                token = strtok(NULL,s);
                continue;
            }
            for (int i = 0;i<len;i++)
            {
                if(key[i] == token[i] || key[i]+32 == token[i] || key[i]-32 == token[i])
                    continue;
                else
                    flag = 0;
            }
            if(flag == 1)
                n++;
            token = strtok(NULL,s);
        }
    }
    printf("%d\n",n);
}
