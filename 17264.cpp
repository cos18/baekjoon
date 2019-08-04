#include <stdio.h>
#include <string.h>

int main(){
    int N, P, W, L, G, score=0;
    char name[1000][20], windata[1000], tmp[20];
    scanf("%d%d%d%d%d", &N, &P, &W, &L, &G);
    for(int i=0;i<P;i++){
        scanf(" %s %c", name[i], &windata[i]);
    }
    while(N--){
        scanf(" %s", tmp);
        for(int i=0;i<P;i++){
            if(!strcmp(tmp, name[i])){
                switch(windata[i]){
                    case 'W':
                        score += W;
                        break;
                    case 'L':
                        score -= L;
                        break;
                    default:
                        break;
                }
                break;
            }
            if(i==P-1) score -= L;
        }
        if(score>=G) break;
        if(score<0) score = 0;
    }
    if(score>=G) printf("I AM NOT IRONMAN!!");
    else printf("I AM IRONMAN!!");
    return 0;
}