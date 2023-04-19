#include <stdio.h>
#include <string.h>
int alpha[26];
char A[100005];
char B[100005];
char C[100005];
int id[100005];
int sub[1000005];
char str[1000005];
int type[100005];
int main(void){
    int n;
    scanf("%s",str);
    scanf("%d",&n);
    int len = strlen(str);
    for (int i = 0;i<n;i++){
        scanf("%d",&type[i]);
        if(type[i] == 1){
            scanf(" %c %c",&A[i],&B[i]);
        }
        if(type[i] == 2){
            scanf(" %d %c",&id[i],&C[i]);
        }
    }
    for (int i = 0;i<26;i++){
        alpha[i] = 'a'+i;
    }
    for (int i = 0;i<len;i++){
        sub[i] = -1;
    }
    for (int i = n-1;i>=0;i--){
        if(type[i] == 1){
            alpha[A[i]-'a'] = alpha[B[i]-'a'];
        }
        else {
            if(sub[id[i]] == -1){
            sub[id[i]] = i;
            C[i] = alpha[C[i]-'a'];
            }
        }
    }
    for (int i = 0;i<len;i++){
        if(sub[i] == -1){
            str[i] = alpha[str[i]-'a'];
            printf("%c",(char)str[i]);
        }
        else {
            str[i] = C[sub[i]];
            printf("%c",(char)str[i]);
        }
    }
    printf("\n");
}
