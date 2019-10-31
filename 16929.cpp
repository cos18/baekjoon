#include <iostream>

using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[50][51];
bool check[50][50];

bool iscycle(int x, int y, int bx, int by){
    if(check[x][y]) return true;
    check[x][y]=true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(bx==nx && by==ny) continue;
        if(map[x][y]!=map[nx][ny]) continue;
        if(iscycle(nx, ny, x, y)) return true;
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(check[i][j]) continue;
            if(iscycle(i, j, -1, -1)){
                cout << "Yes";
                exit(0);
            }
        }
    }
    cout << "No";
}