#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int main(void){
    ///////////input
    char n1[134];
    char n2[134];
    scanf("%s",n1);
    scanf("%s",n2);
    int length1,length2;
    ///////////////////////string length
    for (int i = 0;n1[i]!='\0';i++){
        length1 = i+1;
    }
    for (int i = 0;n2[i]!='\0';i++){
        length2 = i+1;
    }
    /////////////////////append '0'
    int n = abs(length1-length2);
    for (int i = 0;i< n;i++){
        if(length1>=length2){
            for (int j = 0;j<length2+i;j++){
                if(n1[n-i-1]==','){
                    n2[length2+i-j] = n2[length2+i-j-1];
                    if(length2+i-j-1==0)
                        n2[0] = ',';
                }
                else {
                    n2[length2+i-j] = n2[length2+i-j-1];
                    if(length2+i-j-1==0)
                        n2[0] = '0';
                }
            }

        }
        if(length1<length2){
            for (int j = 0;j<length1+i;j++){
                if(n2[n-i-1]==','){
                    n1[length1+i-j] = n1[length1+i-j-1];
                    if(length1+i-j-1==0)
                        n1[0] = ',';
                }
                else {
                    n1[length1+i-j] = n1[length1+i-j-1];
                    if(length1+i-j-1==0)
                        n1[0] = '0';
                }
            }

        }
        }
    /////////////////////////////////plus
    char ans[200];
    int digit = max(length1,length2);
    int c = 0; //carry
    for (int i = 0;i<digit;i++){
        if(n1[digit-1-i]==','){
            ans[digit-1-i]=',';
        }
        else {
            ans[digit-1-i] = (n1[digit-1-i])+(n2[digit-1-i]-'0')+c;
            c = 0;
            if(ans[digit-1-i]>'9'){
                ans[digit-1-i] -= 10;
                c++;
            }
        }
    }
    ///////output
    ans[digit] = '\0';
    if(c!=0&&ans[3]==','){
        printf("1,%s",ans);
    }
    else if (c!=0){
        printf("1%s",ans);
    }
    else {
        printf("%s",ans);
    }
    printf("\n");

}








