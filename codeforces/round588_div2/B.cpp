#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char num[200001];
    int n, k;
    cin >> n >> k;
    cin >> num;
    if(n==1){
        if(k) cout << 0;
        else cout << num;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(!k) continue;
        if(!i){
            if(num[i]=='1') continue;
            num[i]='1';
        } else{
            if(num[i]=='0') continue;
            num[i]='0';
        }
        k--;
    }
    cout << num;
}