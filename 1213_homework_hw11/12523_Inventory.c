#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
int k;

typedef struct
{
    char *name;
    int cur_hp;
    int max_hp;
} Pokemon;

Pokemon *dy_arr(int len)
{
    Pokemon *arr;
    arr = (Pokemon*) malloc(sizeof(Pokemon)*len);
    return arr;
}

void Pokemon_set(char *str,int cur,int max,Pokemon* p)
{
    p->name = str;
    p->cur_hp = cur;
    p->max_hp = max;
}
void Pokemon_show(Pokemon *pok,int len)
{
    for (int i = 0;i<len;i++)
    {
        printf("%s %d %d\n",pok[i].name,pok[i].cur_hp,pok[i].max_hp);
    }
}

void bubblesort(Pokemon *pok);

int main(void)
{
    char s[100][21];
    int cur;
    int max;
    scanf("%d",&n);
    Pokemon *pok = dy_arr(n);
    
    for (int i = 0;i<n;i++)
    {
        
        scanf("%s",s[i]);
        scanf("%d",&cur);
        scanf("%d",&max);
        Pokemon_set(s[i],cur,max,&pok[i]);
    }

    bubblesort(pok);
    Pokemon_show(pok,n);
    free(pok);
}

int compare(Pokemon p1,Pokemon p2)
{
    int flag1 = 0;
    int flag2 = 0;
    if(p1.cur_hp < p1.max_hp)
        flag1 = 1;
    if(p2.cur_hp < p2.max_hp)
        flag2 = 1;

    if(flag1 > flag2)
        return 1;
    else if(flag1 < flag2)
        return -1;
    else
    {
        if(p1.cur_hp < p2.cur_hp)
            return 1;
        else if(p1.cur_hp > p2.cur_hp)
            return -1;
        else
        {
            if(p1.max_hp < p2.max_hp)
                return 1;
            else if(p1.max_hp > p2.max_hp)
                return -1;
            else
                return 0;
        }
    }
}

void bubblesort(Pokemon *pok)
{
    for (int i = 0;i<n-1;i++)
    {
        for (int j = 0;j<n-i-1;j++)
        {
            if(compare(pok[j],pok[j+1]) < 0)
            {
                Pokemon tmp = pok[j];
                pok[j] = pok[j+1];
                pok[j+1] = tmp;
            }
        }
    }
}