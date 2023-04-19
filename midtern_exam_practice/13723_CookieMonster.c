#include <stdio.h>
#include <string.h>

//declaration
int N,K;
char str_input[300];
char d[1000][305];
int cnt[1000];
int len[1000];
int ans[1000];

int comp7(int index_1,int index_2);
int compvalue(int index_1,int index_2);
void sort7();
void sortvalue();
void solve(int num);

//main
int main(void)
{
    //input
    scanf("%d%d",&N,&K);
    for (int i = 0;i<N;i++)
    {
        //input Si
        scanf("%s",str_input);
        //parse
        for (int j = 0,k = 0;str_input[k] != '\0';j = k+1)
        {
            k = j;
            while(str_input[k] != '\0' && str_input[k] != '|')
                k++;
            int num;
            char str_hex[15] = {'\0'};
            char str_dec[15] = {'\0'};
            strncpy(str_hex,str_input+j,k-j);
            sscanf(str_hex,"%x",&num);
            sprintf(str_dec,"%d",num);
            strcat(d[i],str_dec);
        }
        //count 7
        len[i] = strlen(d[i]);
        for (int j = 0;j<len[i];j++)
        {
            if(d[i][j] == '7')
                cnt[i]++;
        }
    }
    solve(K);
}

//function
void solve(int num)
{
    for (int i = 0;i<N;i++)
    {
        ans[i] = i;
    }

    sort7();
    sortvalue();

    for (int i = 0;i<K;i++)
    {
        printf("%s\n",d[ans[i]]);
    }
}

void sort7()
{
    for (int i = 0;i<N-1;i++)
    {
        for (int j = 0;j<N-i-1;j++)
        {
            if(comp7(ans[j],ans[j+1])<0)
            {
                int temp = ans[j+1];
                ans[j+1] = ans[j];
                ans[j] = temp;
            }
        }
    }
}

int comp7(int index_1,int index_2)
{
    if(cnt[index_1] > cnt[index_2])
        return 1;
    else if(cnt[index_1] < cnt[index_2])
        return -1;
    else
    {
        if(len[index_1] > len[index_2])
            return 1;
        else if(len[index_1] < len[index_2])
            return -1;
        else
        {
            int comp = strcmp(d[index_1],d[index_2]);
            if(comp > 0)
                return 1;
            else if(comp < 0)
                return -1;
            else
                return 0;
        }
    }
}

void sortvalue()
{
    for (int i = 0;i<K-1;i++)
    {
        for (int j = 0;j<K - i - 1;j++)
        {
            if(compvalue(ans[j],ans[j+1]) > 0)
            {
                int temp = ans[j+1];
                ans[j+1] = ans[j];
                ans[j] = temp;
            }
        }
    }
}

int compvalue(int index_1,int index_2)
{
    if(len[index_1] > len[index_2])
        return 1;
    else if(len[index_1] < len[index_2])
        return -1;
    else
    {
        int comp = strcmp(d[index_1],d[index_2]);
        return comp;
    }
}



