#include <stdio.h>

int main(void){
    float a,b;
    char c;
    scanf("%f %c %f",&a,&c,&b);
    if(c=='+')
        printf("%5.3f\n",a+b);
    else if(c=='-')
        printf("%5.3f\n",a-b);
    else if(c=='*')
        printf("%5.3f\n",a*b);
    else if(c=='/')
        printf("%5.3f\n",a/b);




}
