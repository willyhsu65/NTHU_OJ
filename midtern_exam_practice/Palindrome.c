#include <stdio.h>
#include <string.h>

char str[1000001];

int main (void){
    int n = 0;
    int flag[1000];
    while((gets(str)) != NULL){
        int len = strlen(str);
        if(len==1){
            flag[n] = 1;
            n++;
            continue;
        }
        for (int i = 0;i<len/2;i++){
            flag[n] = 1;
            if(str[i]!=str[len-i-1]){
                flag[n] = 0;
                break;
            }
        }
        n++;
    }
    for (int i = 0;i<n;i++){
        if(flag[i])
            printf("Yes\n");
        else
            printf("No\n");
    }
}
