#include <stdio.h>

int main(void)
{
    int n;
    int m;
    int cost[1005] = {0};
    int bills[1005] = {0};
    int bill_id = 0;
    int games_id = 0;
    int games = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&cost[i]);
    }
    for (int i = 0;i<m;i++)
    {
        scanf("%d",&bills[i]);
    }
    while(bill_id < m && games_id < n)
    {
        if(cost[games_id] > bills[bill_id])
            games_id++;
        else if(cost[games_id] <= bills[bill_id])
        {
            games_id++;
            bill_id++;
            games++;
        }
    }
    printf("%d\n",games);
}