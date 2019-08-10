#include <stdio.h>

struct point{
    int x;
    int y;
};

int main(){
    point p[100000];
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d%d", &((p+i)->x), &((p+i)->y));
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if( (p+i)->x > (p+j)->x // x좌표가 정렬되어있지 않았거나
                || ( (p+i)->x == (p+j)->x && (p+i)->y > (p+j)->y)){ // x좌표가 동일할 때 y좌표가 정렬되어있지 않았을 때
                // x좌표 swap
                (p+i)->x = (p+i)->x ^ (p+j)->x;
                (p+j)->x = (p+i)->x ^ (p+j)->x;
                (p+i)->x = (p+i)->x ^ (p+j)->x;

                // y좌표 swap
                (p+i)->y = (p+i)->y ^ (p+j)->y;
                (p+j)->y = (p+i)->y ^ (p+j)->y;
                (p+i)->y = (p+i)->y ^ (p+j)->y;
            }
        }
    }
    for(int i=0;i<N;i++){
        printf("%d %d\n", (p+i)->x, (p+i)->y);
    }
}