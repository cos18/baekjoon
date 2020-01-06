#include <iostream>
using namespace std;

int N, K, memo[201][201]={};

int go(int now, int times){
    if(!memo[now][times]) {
        int ans = 0;
        if(times==1) ans=1;
        else{
            for(int i=0;i<=now;i++){
                ans += go(i, times-1);
                ans %= 1000000000;
            }
        }
        memo[now][times]=ans;
    }
    return memo[now][times];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    cout << go(N, K);

    return 0;
}
