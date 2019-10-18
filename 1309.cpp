#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int zoo[100000][3]={};
    zoo[0][0] = zoo[0][1] = zoo[0][2] = 1;
    for(int i=1;i<100000;i++){
        zoo[i][0] = ((zoo[i-1][0] + zoo[i-1][1])%9901 + zoo[i-1][2])%9901;
        zoo[i][1] = (zoo[i-1][0] + zoo[i-1][2])%9901;
        zoo[i][2] = (zoo[i-1][0] + zoo[i-1][1])%9901;
    }
    int n;
    cin >> n;
    if(n!=100000) cout << zoo[n][0];
    else cout << ((zoo[99999][0] + zoo[99999][1])%9901 + zoo[99999][2])%9901;
}