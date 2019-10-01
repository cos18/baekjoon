#include <iostream>
using namespace std;

long long calc(long long n) {
    long long ans = 0, start=1, len=1;
    while (true){
        long long end = start*10-1;
        if(end>n) end=n;
        ans += (end-start+1)*len;
        len++;
        start*=10;
        if(start>n) break;
    }
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long k;
    cin >> n >> k;
    if (calc(n) < k) {
        cout << -1 << '\n';
        return 0;
    }
    int left = 1;
    int right = n;
    int ans = 0;
    while (left <= right) {
        int mid = (left+right)/2;
        long long len = calc(mid);
        if (len < k) {
            left = mid+1;
        } else {
            ans = mid;
            right = mid-1;
        }
    }
    string s = to_string(ans);
    long long l = calc(ans);
    cout << s[s.size()-(l-k)-1];
    return 0;
}