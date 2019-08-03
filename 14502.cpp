#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, lab[8][8]={};
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> lab[i][j];
        }
    }

}