#include <iostream>
using namespace std;

int times(int n){
    if(n==0) return 1;
    if(n==1) return 2;
    else return ((times(n-1)%1000000007)*2)%1000000007;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, w, r[1001], c[1001], map[1001][1001], left;
    cin >> h >> w;
    left = h*w;
    for(int i=0;i<h;i++){
        cin >> r[i];
    }
    for(int i=0;i<w;i++){
        cin >> c[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) {
            map[i][j]=-1;
        }
    }
    for(int i=0;i<h;i++){
        int j;
        for(j=0;j<r[i];j++){
            map[i][j]=1;
        }
        left -= (r[i]+1);
        if(r[i]!=w) map[i][j]=0;
        else left++;
    }
    for(int j=0;j<w;j++){
        int i;
        for(i=0;i<c[j];i++){
            if(map[i][j]==-1){
                map[i][j]=1;
                left--;
            } else {
                if(!map[i][j]){
                    cout << 0;
                    return 0;
                }
            }
        }
        if(c[j]!=h){
            if(map[i][j]==-1){
                map[i][j]=0;
                left--;
            } else if(map[i][j]) {
                cout << 0;
                return 0;
            }
        }
    }
    cout << times(left);
    return 0;
}