#include <stdio.h>
int w[21][21][21], check[21][21][21]={};

int go(int a, int b, int c){
    if (a<=0 || b<=0 || c<=0){
        if(a>=0 && b>=0 && c>=0){
            if (!check[a][b][c]){
                check[a][b][c]=1;
                w[a][b][c]=1;
            }
            return w[a][b][c];
        }
        return 1;
    }
    if (a>20 || b>20 || c>20) return go(20, 20, 20);
    if (!check[a][b][c]){
        if (a<b && b<c) w[a][b][c] = go(a,b,c-1) + go(a,b-1,c-1) - go(a,b-1,c);
        else w[a][b][c] = go(a-1,b,c) + go(a-1,b-1,c) + go(a-1,b,c-1) - go(a-1,b-1,c-1);
        check[a][b][c]=1;
    }
    return w[a][b][c];
}

int main(){
    int a, b, c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a==-1&&b==-1&&c==-1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, go(a, b, c));
    }
}