#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, w[100], v[100], d[100][100001]={};
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i){
                d[i][j] = (w[i]<=j)?max(d[i-1][j], d[i-1][j-w[i]]+v[i]):d[i-1][j];
            } else {
                d[i][j] = (w[i]<=j)?v[i]:0;
            }
        }
    }
    cout << d[n-1][k];
    return 0;
}