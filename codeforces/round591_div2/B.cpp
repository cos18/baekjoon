#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        string a, b;
        cin >> a;
        cin >> b;
        int alpha[26]={};
        for(int i=0;i<a.size();i++){
            alpha[a[i]-'a'] = 1;
        }
        int check = 0;
        for(int j=0;j<b.size();j++){
            if(alpha[b[j]-'a']){
                check = 1;
                break;
            }
        }
        if(check) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}