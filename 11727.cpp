#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tiles[1001]={0, 1, 3}, n;
    for(int i=3;i<=1000;i++){
        tiles[i] = (tiles[i-1] + (2*tiles[i-2])%10007)%10007;
    }
    cin >> n;
    cout << tiles[n];
}