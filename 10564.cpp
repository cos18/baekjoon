#include <iostream>
#include <vector>

using namespace std;

int N, M, point[10], maxpoint[5001][5001];

void go(int now, int points){
    for(int i=0;i<M;i++){
        int nowpoint = now+points+point[i];
        if(nowpoint>N || maxpoint[nowpoint][points+point[i]]) continue;
        maxpoint[nowpoint][points+point[i]]=1;
        go(nowpoint, points+point[i]);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i=1;i<=N;i++){
            memset(maxpoint[i], 0, sizeof(int)*(N+1)); //모든 값 0으로 초기화
        }
        for(int i=0;i<M;i++){
            cin >> point[i];
            maxpoint[point[i]][point[i]] = 1;
        }
        for(int i=0;i<M;i++){
            go(point[i], point[i]);
        }
        int i;
        for(i=N;i>0;i--){
            if(maxpoint[N][i]){
                cout << i << endl;
                break;
            }
        }
        if(i==0) cout << -1 << endl;
    }
}