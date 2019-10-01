#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long pinary[91][2]={}, n;
    pinary[1][1]=1;
    for(int i=2;i<=90;i++){
        pinary[i][1] = pinary[i-1][0];
        pinary[i][0] = pinary[i-1][0] + pinary[i-1][1];
    }
    cin >> n;
    cout << pinary[n][0] + pinary[n][1];
}