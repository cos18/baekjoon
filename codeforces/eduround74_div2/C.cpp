#include <iostream>

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int h, n, p[200000];
        cin >> h >> n;
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        int locate=0, ans = 0;
        while(true){
            if(locate>=n-1 || p[locate]<3) break;
            if(p[locate]-1==p[locate+1]){
                if(locate==n-2){
                    ans++;
                    locate+=2;
                } else if(p[locate+2]==p[locate]-2){
                    locate = locate+2;
                } else{
                    p[locate+1] = p[locate]-2;
                    locate++;
                    ans++;
                }
            } else{
                p[locate]=p[locate+1]+1;
            }
        }
        cout << ans << '\n';
    }
}