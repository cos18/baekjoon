#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n<4) cout << 4-n << '\n';
        else cout << n%2 << '\n';
    }
}