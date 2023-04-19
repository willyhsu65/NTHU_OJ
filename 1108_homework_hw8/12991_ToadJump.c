#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int h[15+1];
int c[15+1];
int jump[15+1] = {0};
int route[15];
int menergy = INT_MIN;
int mjumps = INT_MIN;

int cost(int jumps)
{
    int totenergy = 0;
    for (int i = 0;i<jumps;i++){
        totenergy += abs(h[route[i]] - h[route[i+1]])*abs(route[i] - route[i+1]);
    }
    return totenergy;
}

void jumping(int s,int f,int n,int step)
{
    if(s == f)
    {
        int cenergy = 0;
        cenergy = cost(step-1);
        if(cenergy>menergy){
            menergy = cenergy;
            mjumps = step-1;
        }
        else if(cenergy == menergy && step-1>mjumps){
            mjumps = step-1;
        }
        return;
    }
    else{
    jump[s] = 1;
    if(s+1<= n && jump[s+1]!=1){
        route[step] = s+1;
        jumping(s+1,f,n,step+1);

    }
    if(s-1>= 1 && jump[s-1]!=1){
        route[step] = s-1;
        jumping(s-1,f,n,step+1);
    }
    for (int i = 1;i<=n;i++){
        if(c[i] == c[s] &&i!=s && jump[i]!=1 ){
            route[step] = i;
            jumping(i,f,n,step+1);
        }
    }
    jump[s] = 0;
    }
}
int main(void)
{
    int n;
    int s;
    int f;
    scanf("%d%d%d",&n,&s,&f);
    for (int i = 1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    for (int i = 1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    route[0] = s;
    jumping(s,f,n,1);
    printf("%d %d\n",menergy,mjumps);
}
