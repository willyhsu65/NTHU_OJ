#include <stdio.h>

int StairsClimbing(int n){
    if(n == 1||n == 0){
        return 1;
    }
    return StairsClimbing(n-1) + StairsClimbing(n-2);

}

int main(void){
    int n;
    int a;
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        scanf("%d",&a);
        int ways = StairsClimbing(a);
        printf("%d\n",ways);
    }

}
