#include <iostream>
using namespace std;

int newdis(int x, int y, int i){
    if(x>y){
        x = x^y;
        y = x^y;
        x = x^y;
    }
    if(x==i){
        return (y<i)?y:y-1;
    }
    if(y==i){
        return (x<i)?x:x-1;
    }
    if(y<=i-1 || i+1<=x) return y-x;
    return y-x-1;
}

int pos(int i, int val){
    if(val==i) return 1;
    if(i<val) return val;
    return val+1;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x[200000]={};
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x[i];
    }
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=0;j<m-1;j++){
            int cal = newdis(x[i], x[i+1], i);
            if(cal<0) sum-=cal;
            else sum+=cal;
        }
        cout << sum << " ";
    }
}