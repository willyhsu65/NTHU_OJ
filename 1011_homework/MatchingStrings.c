#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char s1[101][1001];
    char s2[101][1001];
    int n;
    int m;
    int flag = 0;

    scanf("%d %d",&n,&m);
    for (int i = 0;i<n;i++){
        scanf("%s",s1[i]);
    }
    for (int i = 0;i<m;i++){
        scanf("%s",s2[i]);
    }

    for (int i = 0;i<m;i++){
        int len2 = strlen(s2[i]);
        for (int j = 0;j<n;j++){
            int len1 = strlen(s1[j]);
            if(len1==len2&&strstr(s1[j],s2[i])){
                flag = 1;
                break;
            }
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
        flag = 0;

}
}
