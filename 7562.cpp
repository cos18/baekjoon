#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;

    while(q--){
        int l, sx, sy, ex, ey;
        cin >> l >> sx >> sy >> ex >> ey;
        queue<tuple<int, int, int>> wait;
        bool check[500][500]={};
        wait.emplace(sx, sy, 0);
        check[sx][sy] = true;
        int times = 0;
        while(!wait.empty()) {
            int nx, ny;
            tie(nx, ny, times) = wait.front();
            wait.pop();
            if (nx == ex && ny == ey) {
                break;
            }
            for (int i = 0; i < 8; i++) {
                int x = nx + dx[i], y = ny + dy[i];
                if (x < 0 || x >= l || y < 0 || y >= l || check[x][y]) continue;
                check[x][y] = true;
                wait.emplace(x, y, times + 1);
            }
        }
        cout << times << '\n';
    }
}