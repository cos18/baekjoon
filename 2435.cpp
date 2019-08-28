#include <stdio.h>

int main(){
    int N, K, temp[100], max, check = 0;
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++) scanf("%d", &temp[i]);
    for(int i=0;i<K;i++) check += temp[i];
    max = check;
    for(int loc=0;loc<N-K;loc++){
        check -= temp[loc];
        check += temp[loc+K];
        if(max<check) max = check;
    }
    printf("%d\n", max);
}