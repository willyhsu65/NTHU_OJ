#include <stdio.h>
#define MAX_SIZE 10000005
int num[1000001] = {0};
long long pre[MAX_SIZE] = {0};
int answer[1000001] = {0};
int main(void){
    int n;
    scanf("%d",&n);

    for (int i = 1;i<n+1;i++){
        scanf("%d",&num[i]);
    }
    for (int i = 1;i<n+1;i++){
        pre[i] = pre[i-1] + num[i];
    }
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        int left,right;
        scanf("%d %d",&left,&right);
        answer[i] = pre[right] - pre[left-1];
    }
    for (int i = 0;i<n;i++){
        printf("%d\n",answer[i]);
    }
}
