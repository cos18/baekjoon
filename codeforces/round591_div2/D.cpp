#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n, num[300000], check[300001]={}, cnt = 0, before, cnt2=0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> num[i];
        }
        before=num[0];
        for(int i=1;i<n;i++){
            if(!check[num[i]] && num[i-1]>num[i]){
                check[num[i]]=1;
                cnt2++;
            }
            if(before>num[i]){
                cnt++; cnt2--;
            } else before=num[i];
        }
        cnt2 = (n-cnt-cnt2<cnt2)?n-cnt-cnt2:cnt2;
        cout << cnt + cnt2 << '\n';
    }
}