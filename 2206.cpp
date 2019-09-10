#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int map[1001][1001], sketch[1001][1001][2]={}, N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> s;
        for(int j=0;j<M;j++){
            map[i][j+1] = s[j]-'0';
        }
    }
    sketch[1][1][0]=1;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(1, 1, 0));
    while(!q.empty()){
        int x, y, broken;
        tie(x, y, broken) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(x>0 && y>0 && x<=N && y<=M){
                if(map[nx][ny]==0 && sketch[nx][ny][broken]==0){
                    sketch[nx][ny][broken] = sketch[x][y][broken] + 1;
                    q.push(make_tuple(nx, ny, broken));
                }
                if(broken==0 && map[nx][ny]==1 && sketch[nx][ny][broken+1]==0){
                    sketch[nx][ny][1] = sketch[x][y][broken] + 1;
                    q.push(make_tuple(nx, ny, 1));
                }
            }
        }
    }
    if(!sketch[N][M][0]){
        if(!sketch[N][M][1]){
            cout << -1 << '\n';
        } else cout << sketch[N][M][1] << '\n';
    } else if(!sketch[N][M][1]){
        cout << sketch[N][M][0] << '\n';
    } else cout << ((sketch[N][M][0]>sketch[N][M][1])?sketch[N][M][1]:sketch[N][M][0]) << '\n';
}