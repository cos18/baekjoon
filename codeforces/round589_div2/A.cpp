#include <iostream>
using namespace std;

bool isdiff(int n){
    int c[10]={};
    while(true){
        c[n%10]++;
        n/=10;
        if(n==0) break;
    }
    for(int i=0;i<10;i++){
        if(c[i]>1) return false;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r;
    cin >> l >> r;
    for(int i=l;i<=r;i++){
        if(isdiff(i)){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}