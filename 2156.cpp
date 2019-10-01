#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tiles[10001], n, wines[10001][3]={};
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> tiles[i];
    }
    wines[1][1] = tiles[1];
    for(int i=2;i<=n;i++){
        wines[i][1] = wines[i-1][0] + tiles[i];
        wines[i][2] = wines[i-1][1] + tiles[i];
        wines[i][0] = max(max(wines[i-1][0], wines[i-1][1]), wines[i-1][2]);
    }
    cout << max(max(wines[n][0], wines[n][1]), wines[n][2]);
}