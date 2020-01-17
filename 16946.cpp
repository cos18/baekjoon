#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int N, M, map[1000][1000], group[1000][1000];
bool check[1000][1000];
vector<int> group_cnt;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void go(int sx, int sy) {
    int g = group_cnt.size();
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    check[sx][sy] = true;
    group[sx][sy] = g;
    int cnt = 1;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (map[nx][ny] == 0 && check[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                    group[nx][ny] = g;
                    cnt += 1;
                }
            }
        }
    }
    group_cnt.push_back(cnt);
}
int main() {
    cin >> N >> M;
    for (int i=0; i < N; i++) {
        string s;
        cin >> s;
        for (int j=0; j < M; j++) {
            map[i][j] = s[j] - '0';
            check[i][j] = false;
            group[i][j] = -1;
        }
    }
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            if (map[i][j] == 0 && check[i][j] == false) {
                go(i, j);
            }
        }
    }
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            if (map[i][j] == 0) {
                cout << 0;
            } else {
                set<int> near;
                for (int k=0; k<4; k++) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if (0 <= x && x < N && 0 <= y && y < M) {
                        if (map[x][y] == 0) {
                            near.insert(group[x][y]);
                        }
                    }
                }
                int ans = 1;
                for (int g : near) {
                    ans += group_cnt[g];
                }
                cout << ans%10;
            }
        }
        cout << '\n';
    }
    return 0;
}

