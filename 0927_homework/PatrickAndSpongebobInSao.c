#include <stdio.h>

int main(void){
    int n;
    int dish[500] = {0};
    int times;
    int l,r;
    int max[500] = {0};
    int max_times = 0;
    scanf("%d",&n);
    int i = 0;
    while(i<n){
        scanf("%d",&dish[i]);
        i++;
    }
    scanf("%d",&times);
    i = 0;
    while(i<times){
        scanf("%d %d",&l,&r);
        int j = l;
        int dish_times[500] = {0};
        while(j<=r){
          dish_times[dish[j-1]-1]++;
          if(dish_times[dish[j-1]-1]>max_times){
            max[i] = dish[j-1];
            max_times = dish_times[dish[j-1]-1];
          }
          if(dish_times[dish[j-1]-1]==max_times&&dish[j-1]<max[i]){
            max[i] = dish[j-1];
            max_times = dish_times[dish[j-1]-1];
          }
          j++;
        }
        max_times = 0;
        i++;
    }
    i = 0;
    while(i<times){
        printf("%d\n",max[i]);
        i++;
    }
}
