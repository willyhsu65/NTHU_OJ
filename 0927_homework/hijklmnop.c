#include <stdio.h>

int main(void){
    char s[10];
    char in[5];
    scanf("%s",s);
    int trans[10] = {0};
    int i = 0;
    while(i<9){
        trans[i] = s[i]-('1'+i);
        i++;
    }
    scanf("%s",in);
    i = 0;
    while(i<5){
        if(in[i]>'9'){
            int j = 0;
            while(j<10){
                if(in[i]==s[j]){
                    printf("%c",in[i]-trans[j]);
                }
                j++;
            }
        }
        else if(in[i]<='9'){
            int j = 0;
            while(j<10){
                if(in[i]=='1'+j){
                    printf("%c",in[i]+trans[j]);
                }
                j++;
            }
        }
        i++;
    }





}
