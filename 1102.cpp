#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
int n, k;
string buf;
int map[16][16] = {};
int dp[17][65000];
int go(int level, int state) {
    if (level >= k) {
        return 0;
    }
    if (~dp[level][state]) {
        return dp[level][state];
    }
    dp[level][state] = 2e9;
    for (int i = 0; i < n; i++) {
        if (state & (1 << i)) {
            for (int j = 0; j < n; j++) {
                if (!(state & (1 << j))) {
                    dp[level][state] = min(dp[level][state], go(level + 1, state | (1 << j)) + map[i][j]);
                }
            }
        }
    }
    return dp[level][state];
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cin >> buf >> k;
    memset(dp, -1, sizeof(dp));

    int curon = 0, state = 0;
    for (int i = 0; i < n; i++) {
        if (buf[i] == 'Y') {
            curon += 1;
            state |= (1 << i);
        }
    }
    if (curon >= k) {
        cout << 0;
        return 0;
    }
    int ans = go(curon, state);
    cout << (ans==2e9?-1:ans);
}