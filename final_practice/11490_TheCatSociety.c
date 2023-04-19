#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map[8][15] = 
{
    {'e','l','d','e','r','\0'},
    {'n','u','r','s','y','\0'},
    {'k','i','t','t','y','\0'},
    {'w','a','r','r','i','o','r','\0'},
    {'a','p','p','r','e','n','t','i','c','e','\0'},
    {'m','e','d','i','c','e','n','t','\0'},
    {'d','e','p','u','t','y','\0'},
    {'l','e','a','d','e','r','\0'}
};

typedef struct
{
    char *name;
    char *occupations;
    int age;
} Cat;

Cat *dyarr(int len)
{
    Cat *arr;
    arr = (Cat *) malloc(sizeof(Cat)*len);
    return arr;
}

void Cat_set(char *str1,char *str2,int n,Cat *c)
{
    c -> name = str1;
    c -> occupations = str2;
    c ->age = n;
}
int compare(const void*c1v,const void*c2v)
{
    Cat* c1 = (Cat*)c1v;
    Cat* c2 = (Cat*)c2v;
    int occ1 = 0,occ2 = 0;
    for (int i = 0;i<8;i++)
    {
        if(strcmp(c1->occupations,map[i]) == 0)
        {
            occ1 = i;
        }
        if(strcmp(c2->occupations,map[i]) == 0)
        {
            occ2 = i;
        }
    }
    if(occ1 > occ2)
        return 1;
    else if(occ1 < occ2)
        return -1;
    else if(occ1 == occ2)
    {
        if(occ1 == 4)
        {
            if(c1->age > c2->age)
                return 1;
            else if(c1->age < c2->age)
                return -1;
            else if(c1->age == c2->age)
                return strcmp(c1->name,c2->name);
        }
        else
        {
            if(c1->age > c2->age)
                return -1;
            else if(c1->age < c2->age)
                return 1;
            else if(c1->age == c2->age)
                return strcmp(c1->name,c2->name);
        }
    }
}
void bubblesort(Cat *c,int n)
{
    for (int i = 0;i<n-1;i++)
    {
        for (int j = 0;j<n-i-1;j++)
        {
            if(compare(&c[j],&c[j+1]) > 0)
            {
                Cat temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int n,m;
    while((scanf("%d%d",&n,&m) != EOF))
    {
        char name[10005][35] = {'\0'};
        char ocu[10005][15] = {'\0'};
        int age = 0;
        Cat *catarr = dyarr(n);
        for (int i = 0;i<n;i++)
        {
            scanf("%s %s %d",name[i],ocu[i],&age);
            Cat_set(name[i],ocu[i],age,catarr+i);
        }
        qsort(catarr,n,sizeof(Cat),compare);
        if(n < m)
            m = n;
        for (int i = 0;i<m;i++)
        {
            printf("%s\n",catarr[i].name);
        }
        free(catarr);
    }
}