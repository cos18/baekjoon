#include <stdio.h>
#include <math.h>

int z(int n, int r, int c){
    if(n==1)
        return r*2+c;
    int sum=0;
    if(r>=pow(2, n-1)){
        sum += pow(2,2*n-1);
        r -= pow(2, n-1);
    }
    if(c>=pow(2, n-1)){
        sum += pow(4,n-1);
        c -= pow(2, n-1);
    }
    return sum + z(n-1,r,c);
}

int main(int argc, const char * argv[]) {
    int N, R, C;
    scanf("%d%d%d", &N, &R, &C);
    printf("%d", z(N, R, C));
    return 0;
}