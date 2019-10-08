#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n, sum=0, tmp;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> tmp;
            sum += tmp;
        }
        cout << (sum-1)/n+1 << '\n';
    }
}