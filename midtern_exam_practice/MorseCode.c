#include <stdio.h>
#include <string.h>

char code[26][5] =
{
    {'*','-'}, //A
    {'-','*','*','*'}, //B
    {'-','*','-','*'}, //C
    {'-','*','*'}, //D
    {'*'}, //E
    {'*','*','-','*'}, //F
    {'-','-','*'}, //G
    {'*','*','*','*'}, //H
    {'*','*'}, //I
    {'*','-','-','-'}, //J
    {'-','*','-'}, // K
    {'*','-','*','*'}, // L
    {'-','-'}, //M
    {'-','*'}, //N
    {'-','-','-'}, //O
    {'*','-','-','*'}, //P
    {'-','-','*','-'}, //Q
    {'*','-','*'}, //R
    {'*','*','*'}, //S
    {'-'}, //T
    {'*','*','-'}, //U
    {'*','*','*','-'}, //V
    {'*','-','-'}, //W
    {'-','*','*','-'}, //X
    {'-','*','-','-'}, //Y
    {'-','-','*','*'}, //Z
};
char tmp[400][60];

int main(void)
{
    char map[27][50] = {'\0'};
    for (int i = 0;i<26;i++)
    {
        int len = strlen(code[i]);
        for (int j = 0;j<len;j++)
        {
            char c = code[i][j];
            if(c == '*')
            {
                strcat(map[i],"=.");
            }
            else
            {
                strcat(map[i],"===.");
            }
        }
        map[i][strlen(map[i])-1] = '\0';
    }
    strcat(map[26]," "); //for space

    char input[1005];
    int n;
    int dot = 0;
    int last = 0;
    scanf("%d",&n);
    scanf("%s",input);

    for (int i = 0;i<n;i++)
    {
        char c = input[i];
        tmp[last][strlen(tmp[last])] = c;
        if(c == '.')
        {
            dot += 1;
        }
        else
        {
            dot = 0;
        }
        if(dot == 3)
        {
            tmp[last][(int)strlen(tmp[last])-3] = '\0';
            last++;
        }
        if(dot == 7)
        {
            strcpy(tmp[last]," ");
            last++;
        }
    }
    //output
    for (int i = 0;i<=last;i++)
    {
        for (int j = 0;j<27;j++)
        {
            if(strcmp(tmp[i],map[j]) == 0)
            {
                if(j == 26)
                    printf(" ");
                else
                    printf("%c",'A'+j);
            }
        }
    }
    printf("\n");
}
