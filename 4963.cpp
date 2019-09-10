#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int w, h, map[50][50], visit[50][50]={}, cnt;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void bfs(int x, int y){
    if(!map[x][y] || visit[x][y]) return;
    cnt++;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = cnt;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=w || ny >=h || nx<0 || ny<0) continue;
            if(map[nx][ny] && !visit[nx][ny]){
                visit[nx][ny] = cnt;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true){
        cin >> h >> w;
        if(!(w&&h)) break;
        cnt=0;
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                cin >> map[i][j];
                visit[i][j]=0;
            }
        }
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                bfs(i, j);
            }
        }
        cout << cnt << "\n";
    }
}