#include <iostream>
#include <queue>
#include <tuple>
#define MAX 100000
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.emplace(0, N);

    int ans = 0, check[100001]={};

    while(!q.empty()){
        int num;
        tie(ans, num) = q.front();
        q.pop();
        if(num==K) break;
        check[num] = 1;
        if(num>0 && !check[num-1]) q.emplace(ans+1, num-1);
        if(num<MAX && !check[num+1]) q.emplace(ans+1, num+1);
        if(num*2<=MAX && !check[num*2]) q.emplace(ans+1, num*2);
    }
    cout << ans;

    return 0;
}
