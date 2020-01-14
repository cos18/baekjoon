#include <iostream>
using namespace std;

int dp[10001], cost[101];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        cin >> cost[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = cost[i]; j <= k; j++)
            dp[j] += dp[j - cost[i]];
    }

    cout << dp[k];
    return 0;
}