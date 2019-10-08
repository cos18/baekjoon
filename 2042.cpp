#include <iostream>
#include <vector>
using namespace std;

long long sum (vector<long long> &fan, int i){
    long long ans = 0;
    while(i>0){
        ans += fan[i];
        i -= (i&-i);
    }
    return ans;
}

void update(vector<long long> &fan, int i, long long d){
    while(i<fan.size()){
        fan[i] += d;
        i += (i&-i);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K, q, a, b;
    cin >> N >> M >> K;
    M += K;
    vector<long long> arr(N+1);
    vector<long long> fenwick(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        update(fenwick, i, arr[i]);
    }
    while(M--){
        cin >> q >> a >> b;
        if(q==1){
            int d = b- arr[a];
            arr[a] = b;
            update(fenwick, a, d);
        } else cout << sum(fenwick, b)-sum(fenwick, a-1) << '\n';
    }
}