#include <iostream>
#define DIV 15746
using namespace std;

int memo[1000001]={0, 1, 2, 3};

int go(int n){
    if(!memo[n]){
        memo[n] = go(n-1)+go(n-2);
        memo[n] %= DIV;
    }
    return memo[n];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << go(n);
    return 0;
}
