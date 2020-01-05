#include <iostream>
#include <algorithm>
using namespace std;

int diff[15], N, L, R, X;

int go(int locate, long long sum, int lmin, int lmax){
    if(locate==N){
        if(L<=sum && sum<=R && X<=lmax-lmin) return 1;
        return 0;
    }
    int ans = 0;
    long long newsum = sum+diff[locate];
    if(newsum<=R){
        ans += go(locate+1, newsum, min(lmin, diff[locate]), max(lmax, diff[locate]));
    }
    ans += go(locate+1, sum, lmin, lmax);
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R >> X;
    for(int i=0;i<N;i++){
        cin >> diff[i];
    }

    cout << go(0, 0, 1000001, 0);

    return 0;
}
