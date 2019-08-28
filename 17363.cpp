#include <stdio.h>

int main(){
    int N, M;
    char milk[125], pic[100][101];
    milk['.']='.'; milk['O']='O'; milk['-']='|'; milk['|']='-';
    milk['/']='\\'; milk['\\']='/'; milk['^']='<'; milk['<']='v';
    milk['v']='>'; milk['>']='^';
    scanf("%d %d", &N, &M);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%s", pic[i]);
    }
    for(int j=M-1;j>=0;j--){
        for(int i=0;i<N;i++){
            printf("%c", milk[pic[i][j]]);
        }
        printf("\n");
    }
    return 0;
}