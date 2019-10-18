#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        long long x, y;
        cin >> x >> y;
        if(x-y==1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}