#include <stdio.h>

int main(){
    int sum, cha, a, b;
    scanf("%d%d", &sum, &cha);
    a = (sum+cha)/2;
    b = sum-a;
    if(b<0 || (sum+cha)%2) printf("-1");
    else printf("%d %d", a, b);
}