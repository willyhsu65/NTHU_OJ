#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char c;
    char prev;
    int mode = 0;
    //declaration

    while((c = getchar()) != EOF){
        char temp = c;
        //header mode
        if(mode == 0){
            if(c == '\n')
                mode = 1;
        }
        //Indentation mode
        else if(mode == 1){
            if(c == '#')
                mode = 0;
            else if(c == ';'){
                c = ' ';
                }
            else if(c=='}'&& prev == ';'){
                mode = 3;
            }
            else {
                mode = 2;
            }
        }
        //coding mode regular cases
        else if(mode == 2){
            if(c == '\n'&&prev!='{'){
                mode = 1;
                putchar(';');
            }
            else if(c == '\n'&&prev == '{'){
                mode = 1;
            }
        }
        //coding mode with ;}
        else if(mode == 3){
            if(c =='\n')
                mode = 1;
        }
        prev = temp;
        putchar(c);
    }

}
