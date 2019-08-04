#include <stdio.h>

int room(int k, int n){
    if(n==0) return 0;
    if(k==0) return n;
    return room(k, n-1) + room(k-1, n);
}

int main(){
    int T, k, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &k, &n);
        printf("%d\n", room(k, n));
    }
}