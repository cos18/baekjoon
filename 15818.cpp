#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N, M;
    cin >> N >> M;
    long long ans = 1;
    while (N--){
        long long in;
        cin >> in;
        ans*=(in%M);
        ans%=M;
    }
    cout << ans;
}