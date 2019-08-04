#include <stdio.h>

int main(){
    int n, m;
    char hot[10][10], tmp;
    scanf("%d%d", &n, &m);
    scanf("%c", &tmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%c", &hot[i][j]);
        }
        scanf("%c", &tmp);
    }
    for(int i=0;i<n;i++) {
        for (int j=m-1;j>=0;j--) {
            printf("%c", hot[i][j]);
        }
        printf("\n");
    }
}