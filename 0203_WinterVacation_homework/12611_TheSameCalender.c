#include <stdio.h>

int IsLeapyear(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)  return 1;
            else return 0;
        }
        else return 1;
    }
    else  return 0;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        int year;
        int d = 0;
        scanf("%d",&year);
        int leapyear = IsLeapyear(year);
        while(1)
        {
            if(IsLeapyear(year))
                d = d+2;
            else
                d++;
            year++;
            if(d % 7 == 0 && IsLeapyear(year) == leapyear)
                break;           
        }
        printf("%d\n",year);
    }
}