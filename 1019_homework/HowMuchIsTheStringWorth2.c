#include <stdio.h>
#include <string.h>
#include <ctype.h>
coin[10000000] = {0};
int main(void){
    char alpha[27];
    char s[101];
    char end[3] = {'e','n','d'};
    int flag = 0;
    int n = 0;

    scanf("%s",alpha);
    getchar();
    while((gets(s))!=NULL){
        int len = strlen(s);
        if((s[0] == end[0]&&s[1]==end[1]&&s[2]==end[2]&&len == 3)||(s[0] == '0'&&len == 1)){
            break;
        }
        for (int i = 0;i<len;i++){
            for (int j = 0;j<26;j++){
                if(s[i]==alpha[j]){
                    coin[n]+=j+1;
                }
            }
        }
        n++;
    }
    while((gets(s))!= NULL){

    }
    for (int i = 0;i<n;i++){
        printf("%d\n",coin[i]);
    }
}
