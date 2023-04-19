#include <stdio.h>
#include <stdlib.h>

char alpha[27];
char A[200005];
char B[200005];
int sub[27];

int main(void)
{
    int len;
    int n;
    for (int i = 0;i<26;i++)
        alpha[i] = 'a' + i;
    alpha[26] = '\0';
    scanf("%d%d",&len,&n);
    char *str = (char *)malloc(sizeof(char)*(len+1));
    scanf("%s",str);
    for (int i = 0;i<n;i++)
    {
        char a,b;
        scanf(" %c %c",&a,&b);
        A[i] = a;
        B[i] = b;
    }
    for (int i = n-1;i>=0;i--)
    {
        char tmp = alpha[A[i] - 'a'];
        alpha[A[i] - 'a'] = alpha[B[i] - 'a'];
        alpha[B[i] - 'a'] = tmp;
    }
    for (int i = 0;i<len;i++)
    {
        printf("%c",alpha[str[i] - 'a']);
    }
    printf("\n");
}