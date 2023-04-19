#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int x;
    int dir;
} particle;

particle *dy_arr(int n)
{
    particle *par = (particle*)malloc(sizeof(particle) * n);
    return par;
}

void particle_set(int a,int d,particle* p)
{
    p->x = a;
    p->dir = d;
}

int IsCollidable(particle *p1,particle *p2)
{
    if(p1->dir == 1 && p2->dir == 0)
        return 1;
    else return 0;
}

int main(void)
{
    int n;
    int mindist = INT_MAX;
    int time;
    scanf("%d",&n);
    particle* par = dy_arr(n);
    for (int i = 0;i < n;i++)
    {
        char c;
        scanf(" %c",&c);
        if(c == 'L') par[i].dir = 0; // L == 0
        else if(c == 'R') par[i].dir = 1; // R == 1
    }
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&par[i].x);
    }
    for (int i = 0;i<n-1;i++)
    {
        if(IsCollidable(&par[i],&par[i+1]))
        {
            if(par[i+1].x - par[i].x < mindist)
            {
                mindist = par[i+1].x - par[i].x;
            }
        }
    }

    if(mindist == INT_MAX)
        time = -1;
    else
        time = mindist/2;
    
    printf("%d\n",time);
}