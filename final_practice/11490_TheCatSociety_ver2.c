#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _cat
{
    int age;
    int occu;
    char *name;
} cat;


int cmp(const void *a,const void *b)
{
    cat *cat1 = (cat *)a;
    cat *cat2 = (cat *)b;
    if(cat1->occu > cat2->occu)
        return 1;
    else if(cat1->occu < cat2->occu)
        return -1;
    else
    {
        if(cat1->occu == 5 && cat2->occu == 5)
        {
            if(cat1->age > cat2->age)
                return 1;
            else if(cat1->age < cat2->age)
                return -1;
            else
                return strcmp(cat1->name,cat2->name);
        }
        else
        {
            if(cat1->age < cat2->age)
                return 1;
            else if(cat1->age > cat2->age)
                return -1;
            else
                return strcmp(cat1->name,cat2->name);
        }
    }
}

cat *dyarr(int n)
{
    cat *arr = (cat*)malloc(sizeof(cat)*n);
    return arr;
}
void cat_set(int occ,char *n,int a,cat *c)
{
    c->age = a;
    c->occu = occ;
    c->name = n;
}

int main(void)
{
    int n,m;

    while(scanf("%d%d",&n,&m) != EOF)
    {
    cat* cat_arr = dyarr(n);
    char occ[30];
    int ages;
    char names[10005][50] = {'\0'};
    for (int i = 0;i<n;i++)
    {
        int o = 0;
        scanf("%s %s %d",names[i],occ,&ages);
        switch(occ[0])
        {
            case 'e':
                o = 1;
                break;
            case 'n':
                o = 2;
                break;
            case 'k':
                o = 3;
                break;
            case 'w':
                o = 4;
                break;
            case 'a':
                o = 5;
                break;
            case 'm':
                o = 6;
                break;
            case 'd':
                o = 7;
                break;
            case 'l':
                o = 8;
                break;
        }
        cat_set(o,names[i],ages,&cat_arr[i]);
    }
    qsort(cat_arr,n,sizeof(cat),cmp);
    if(m > n)
        m = n;
    for (int i = 0;i<m;i++)
    {
        printf("%s\n",cat_arr[i].name);
    }
    }
}