#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k;
    cin >> n >> k;
    long long low = 1, high = min(n*n, 1000000000LL), ans=0;
    while(low<=high){
        long long cnt = 0, mid = (low+high)/2;
        for(int i=1;i<=n;i++){
            cnt += min(mid/i, n);
        }
        if(cnt>=k){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans;
}