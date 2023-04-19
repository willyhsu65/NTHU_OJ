#include <stdio.h>

int board[16][16];
int dir_table[8][2] = {{0,1},{0,-1},{-1,0},{1,0},{-1,1},{1,-1},{1,1},{-1,-1}};
int NCS_total(int player,int x,int y,int dir){
    int NCS = 0;
    while(x>=0&&x<=15&&y>=0&&y<=15&&board[x][y] == player){
        NCS++;
        x += dir_table[dir][0];
        y += dir_table[dir][1];
    }
    return NCS;
}
void PrintWinner(int player,int round){
    if(player == 1)
        printf("LSC wins at the %dth step.\n",round+1);
    else if(player == 2)
        printf("TSC wins at the %dth step.\n",round+1);
}
int Checker(int player,int x,int y,int round){
    int found = 0;
    int dir_pair = 0;
    for (dir_pair = 0;dir_pair<4;dir_pair++){
        int ncs = 0;
        ncs = NCS_total(player,x,y,2*dir_pair)+NCS_total(player,x,y,2*dir_pair+1)-1;
        if(ncs>=5){
            PrintWinner(player,round);
            found = 1;
            break;
        }
    }
    return found;
}
int main(void){
    int n;
    scanf("%d",&n);
    int winner = -1;

    for (int i = 0;i<n;i++){
        int pos_x = -1;
        int pos_y = -1;
        int player = -1;
        scanf("%d %d",&pos_x,&pos_y);
        if(i%2 == 0){
            player = 1;
            board[pos_x][pos_y] = 1;
        }
        else {
            player = 2;
            board[pos_x][pos_y] = 2;
        }
        if(Checker(player,pos_x,pos_y,i)){
            winner = player;
            break;
        }
    }

}
