#include <stdio.h>

int main(){
    int n, k, pick[150], cycle[150]={};
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &pick[i]);
    }
    int turn = 0, times = 0;
    while(1){
        if(pick[turn]==k) break;
        for(int i=0;i<times;i++){
            if(cycle[i]==pick[turn]){
                times = -2;
            }
        }
        if(times==-2) break;
        cycle[times]=turn;
        turn = pick[turn];
        times++;
    }
    printf("%d", times+1);
}