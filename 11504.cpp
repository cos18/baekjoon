#include <stdio.h>
#include <math.h>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M, pan[100]={}, tmp, cnt = 0, position=1;
        long long X=0, Y=0, target = 0;
        scanf("%d %d", &N, &M);
        for(int i=0;i<M;i++){
            scanf("%d", &tmp);
            X = X*10+tmp;
        }
        for(int i=0;i<M;i++){
            scanf("%d", &tmp);
            Y = Y*10+tmp;
        }
        for(int i=0;i<N;i++){
            scanf("%d", &pan[i]);
        }
        for(int i=0;i<M;i++){
            target = target*10 + pan[i];
        }
        if(target>=X && target<=Y) cnt++;
        while(position!=N){
            target -= pan[position-1]*pow(10, M-1);
            target *= 10;
            target += pan[(position+M-1)%N];
            if(target>=X && target<=Y) cnt++;
            position++;
        }
        printf("%d\n", cnt);
    }
}