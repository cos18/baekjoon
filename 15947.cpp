#include <stdio.h>
#include <string.h>

int main(){
    int N;
    char shark[14][15] = {
            "sukhwan", "baby", "sukhwan", "tururu", "turu",
            "very", "cute", "tururu", "turu",
            "in", "bed", "tururu", "turu", "baby"
    };
    char ans[20], turu[4][15] = {"turu", "tururu", "turururu", "tururururu"};
    scanf("%d", &N);
    switch (N%14){
        case 3:
        case 7:
        case 11:
            if(N/14 <= 2) strcpy(ans, turu[N/14+1]);
            else {
                printf("tu+ru*%d", N / 14 + 2);
                return 0;
            }
            break;
        case 4:
        case 8:
        case 12:
            if(N/14 <= 3) strcpy(ans, turu[N/14]);
            else {
                printf("tu+ru*%d", N/14+1);
                return 0;
            }
            break;
        default:
            strcpy(ans, shark[N%14]);
            break;
    }
    printf("%s", ans);
}