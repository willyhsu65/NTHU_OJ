#include <stdio.h>

int main(void){
    //declaration
    int r,c;
    int t;
    char room[101][101];
    int dirr[4] = {1,-1,0,0};
    int dirc[4] = {0,0,1,-1};
    int flag[100][100] = {0};
    //input
    scanf("%d %d %d",&r,&c,&t);
    for (int i = 0;i<r;i++){
        scanf("%s",room[i]);
    }
    //spread
    for (int i = 0;i<t;i++){
        for (int j = 0;j<r;j++){
            for (int k = 0;k<c;k++){
                if(room[j][k] == 'F'&&flag[j][k] == 0){
                    for (int l = 0;l<4;l++){
                        if(room[j+dirr[l]][k+dirc[l]] == '#'){
                            continue;
                        }
                        else if(room[j+dirr[l]][k+dirc[l]] == 'F'){
                            continue;
                        }
                        else if(room[j+dirr[l]][k+dirc[l]] == 'C'){
                            room[j+dirr[l]][k+dirc[l]] = 'F';
                            flag[j+dirr[l]][k+dirc[l]] = 1;
                        }
                    }
                }
            }
        }
        for (int j = 0;j<r;j++){
            for (int k = 0;k<c;k++){
                flag[j][k] = 0;
            }
        }
    }
    //output
    for (int i = 0;i<r;i++){
        printf("%s\n",room[i]);
    }
}
