#include <stdio.h>

int cal[20];
int flag = 0;
int cookies[20];
int tcal(int curr);
void diet(int curr,int i,int c,int n)
{
    if(flag)
        return;
    cookies[curr] = cal[i];
    int total = tcal(curr);
    if(total == c){
        flag = 1;
        return;
    }
    else if(total > c || i == n)
        return;
    else if(total < c){
        for (int j = i+1;j <= n;j++){
            diet(curr+1,j,c,n);
        }
    }

}
int tcal(int curr)
{
    int total = 0;
    for (int i = 0;i<=curr;i++){
        total += cookies[i];
    }
    return total;
}
int main(void){
    int n;
    int c;
    scanf("%d%d",&n,&c);
    for (int i = 0;i<n;i++){
        scanf("%d",&cal[i]);
    }
    for (int i = 0;i<n;i++){
        if(flag)
            break;
        diet(0,i,c,n);
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
}
