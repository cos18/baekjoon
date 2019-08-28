#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
};

int static compare (const void* first, const void* second){
    if (((point*)first)->x > ((point*)second)->x) return 1;
    else if (((point*)first)->x < ((point*)second)->x) return -1;
    else{
        if (((point*)first)->y > ((point*)second)->y) return 1;
        else if (((point*)first)->y < ((point*)second)->y) return -1;
        else return 0;
    }
}

int main(){
    point p[100000];
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d%d", &((p+i)->x), &((p+i)->y));
    }
    qsort(p, N, sizeof(point), );
    for(int i=0;i<N;i++){
        printf("%d %d\n", (p+i)->x, (p+i)->y);
    }
}