#include <iostream>
using namespace std;

int n, map[2][200000]={};

bool go(int bx, int by, int x, int y){
    if(x==1 && y==n) return true;
    if(x==-1 || x==2 || (x==1 && y==-1) || (x==0 && y==n)) return false;
    if(map[x][y]<3) return go(x, y, x+(x-bx), y+(y-by));
    if(y==by) return go(x, y, x, y+1);
    return (go(x, y, x+1, y) || go(x, y, x-1, y));
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        cin >> n;
        string a;
        for(int i=0;i<2;i++){
            cin >> a;
            for(int j=0;j<n;j++){
                map[i][j] = a[j]-'0';
            }
        }
        cout << (go(0, -1, 0, 0)?"YES":"NO") << '\n';
    }
}