#include <cstdio>
using namespace std;

int N, W[10][10], go[10], check[10]={};

// 갈 순서를 정해, 다 정하면 걸리는 비용의 최소값을 반환해준다.
int howtogo(int turn){
    int ans = 1000000*10+1; // 순회 가능한 최대값
    if(turn==N){
        // 순서를 모두 정한 경우, 비용 계산
        if(W[go[N-1]][go[0]]){
            ans = 0;
            for(int i=0;i<N-1;i++){
                ans += W[go[i]][go[i+1]];
            }
            ans += W[go[N-1]][go[0]];
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (check[i]) continue;
            if (turn && !W[go[turn - 1]][i]) continue;
            check[i] = 1;
            go[turn] = i;
            int tmp = howtogo(turn + 1);
            ans = (ans > tmp) ? tmp : ans;
            check[i] = 0;
        }
    }
    return ans;
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &W[i][j]);
        }
    }
    printf("%d\n", howtogo(0));
}