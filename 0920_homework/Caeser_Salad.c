#include <stdio.h>

int main(void){
    int n;
    char s[3];
    scanf("%s %d",s,&n);
    int i = 0;
    n = n%26;
    while(i<3){
        if(s[i]+n>'Z'){
            printf("%c",s[i]+n-'A');
        }
        else if(s[i]+n<'A'){
            printf("%c",s[i]+n+26);
        }
        else {
            printf("%c",s[i]+n);
        }
        i++;
    }
    printf("\n");
}
