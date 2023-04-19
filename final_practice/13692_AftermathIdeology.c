#include <stdio.h>
#include <string.h>

int type[100005];
char input[1000005];
char sub[1000005];
int id1[100005],id2[100005];
int id[100005];
char A[100005],B[100005];
char C[100005];
char alpha[100005][27];
void swap(char *str,int x,int y)
{
    char tmp = str[x];
    str[x] = str[y];
    str[y] = tmp;
}

int main(void)
{
    int q;
    for (int i = 0;i<1000005;i++) sub[i] = -1;
    scanf("%s",input);
    scanf("%d",&q);
    for (int i = 0;i<q;i++)
    {
        scanf("%d",&type[i]);
        if(type[i] == 1) scanf(" %c %c",&A[i],&B[i]);
        else if(type[i] == 2) scanf("%d %c",&id[i],&C[i]);
        else if(type[i] == 3) scanf("%d%d",&id1[i],&id2[i]);
    }
    for (int i = 0;i<26;i++)
    {
        alpha[q][i] = 'a'+i;
    }
    for (int i = q-1;i >= 0;i--)
    {
        for (int j = 0;j<26;j++)
        {
            alpha[i][j] = alpha[i+1][j];
        }
        if(type[i] == 1)
        {
            alpha[i][A[i] - 'a'] = alpha[i][B[i] - 'a'];
        }
    }
    for (int i = 0;i<q;i++)
    {
        if(type[i] == 2)
        {
            sub[id[i]] = alpha[i][C[i] - 'a'];
        }
        else if(type[i] == 3)
        {
            swap(input,id1[i],id2[i]);
            swap(sub,id1[i],id2[i]);
        }
    }
    int len = strlen(input);
    for (int i = 0;i<len;i++)
    {
        char c;
        if(sub[i] == -1)
        {
            c = alpha[0][input[i] - 'a'];
        }
        else
        {
            c = sub[i];
        }
        printf("%c",c);
    }
    printf("\n");
}
