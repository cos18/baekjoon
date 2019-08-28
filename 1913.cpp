#include <stdio.h>

int main(){
    int snail[1001][1001]={};
    for(int i=0;i<1001;i++){
        snail[0][i] = snail[i][0] = -1;
    }
    int N, find, locate, x=1, y=1, fx, fy;
    int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, moveloc=0;
    scanf("%d %d", &N, &find);
    for(int i=0;i<1001;i++){
        snail[N+1][i] = snail[i][N+1] = -1;
    }
    locate = N*N;
    while(locate){
        snail[x][y] = locate;
        if(locate == find){
            fx = x; fy = y;
        }
        x += move[moveloc][0];
        y += move[moveloc][1];
        if(snail[x][y] != 0){
            x -= move[moveloc][0];
            y -= move[moveloc][1];
            moveloc = (moveloc+1)%4;
            x += move[moveloc][0];
            y += move[moveloc][1];
        }
        locate--;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%d ", snail[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", fx, fy);
}