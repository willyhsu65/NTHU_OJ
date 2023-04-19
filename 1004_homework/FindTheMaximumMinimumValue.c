#include <stdio.h>
#include <stdlib.h>

int main(void){
    int array[10][10];
    int row,column;
    int max;
    int min;
    scanf("%d %d",&row,&column);
    for (int i = 0;i<row;i++){
        for (int j = 0;j<column;j++){
            scanf("%d",&array[i][j]);
        }
    }
    max = array[0][0];
    min = array[0][0];
    int rM = 0;
    int rm = 0;
    int cM = 0;
    int cm = 0;
    for (int i = 0;i<row;i++){
        for (int j = 0;j<column;j++){
            if(array[i][j]>max){
                max = array[i][j];
                rM = i;
                cM = j;
            }
            else if(array[i][j]<min){
                min = array[i][j];
                rm = i;
                cm = j;
            }
        }
    }
    printf("%d %d",abs(rM-rm)+abs(cM-cm),max-min);
}
