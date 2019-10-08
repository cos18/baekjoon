#include <iostream>
using namespace std;

int n, map[2][200000]={};

bool go(int bx, int by, int x, int y){
    if(x==1 && y==n) return true;
    if(x==-1 || x==3 || (x==1 && y==-1) || (x==0 && y==n)) return false;
    if(map[x][y]<3) return go(x, y, x+(x-bx), y+(y-by));
    if(y==by) return go(x, y, x, y+1);
    return go(x, y, x+1, y) || go(x, y, x-1, y);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int q;
    cin >> q;

    while(q--){
        int a, b, c;
        cin >> a >> b;
        if(a==1){
            char d;
            cin >> d;
            s[b-1]=d;
        }
        else{
            cin >> c;
            int alpha[26]={}, left=26;
            for(int i=b-1;i<c;i++){
                if(alpha[s[i]-'a']==0){
                    left--;
                    alpha[s[i]-'a']=1;
                }
                if(left==0) break;
            }
            cout << 26-left << '\n';
        }
    }
}