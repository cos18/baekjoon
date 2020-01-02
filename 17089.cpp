#include <iostream>
using namespace std;

int path[4001][4001]={};
int degree[4001]={};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        path[x][y] = path[y][x] = 1;
        degree[x] += 1;
        degree[y] += 1;
    }
    int ans = -1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (path[i][j]) {
                for (int k=1; k<=n; k++) {
                    if (path[i][k] && path[j][k]) {
                        int sum = degree[i] + degree[j] + degree[k] - 6;
                        if (ans == -1 || ans > sum) {
                            ans = sum;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

