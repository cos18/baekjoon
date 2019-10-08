#include <iostream>

using namespace std;
#define INF 100010

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n, a[100], b[100], sum=0, d[100010][2]={};
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i] >> b[i];
            sum += a[i];
        }
        d[0][0] = b[0];
        for(int i=1;i<=sum;i++){
            d[i][0] = (i==a[0])?0:INF;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                d[j][1] = (j>=a[i])?min(d[j][0]+b[i], d[j-a[i]][0]):d[j][0]+b[i];
            }
            for(int j=0;j<=sum;j++){
                d[j][0] = d[j][1];
            }
        }
        int ans = INF;
        for(int i=0;i<=sum;i++){
            ans = min(ans, max(i, d[i][0]));
        }
        cout << ans;
    }
}