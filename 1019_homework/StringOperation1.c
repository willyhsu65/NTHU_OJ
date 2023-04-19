#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
    char s[1000001];
    char alpha[26];
    int n;
    char r,t;
    //declaration

    for (int i = 0;i<26;i++){
        alpha[i] = i+'a';
    }
    //initiation

    scanf("%s",s);
    scanf("%d",&n);
    int len = strlen(s);
    //input

    for (int i = 0;i<n;i++){
        getchar();
        r = getchar();
        getchar();
        t = getchar();
        for (int j = 0;j<26;j++){
            if(alpha[j] == r){
                alpha[j] = t;
            }
        }
    }
    //transform alpha array

    for (int i = 0;i<len;i++){
        s[i] = alpha[s[i]-'a'];
    }
    //transform the string

    printf("%s",s);
    //output
}
