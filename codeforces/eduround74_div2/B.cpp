#include <iostream>
#include <algorithm>

using namespace std;

bool s(int a, int b){
    return a>b;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n, r, x[100000];
        cin >> n >> r;
        for(int i=0;i<n;i++){
            cin >> x[i];
        }
        sort(x, x+n, s);
        int locate=0, end=0, ans = 0;
        while(locate<n){
            int now = x[locate];
            ans++;
            while(now==x[locate]){
                locate++;
                if(locate==n) break;
            }
            end += r;
            if(end>=x[locate]) break;
        }
        cout << ans << endl;
    }
}