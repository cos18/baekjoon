#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, n, w, ans_a, ans_b, check = 0;
    cin >> a >> b >> n >> w;
    for(int i=1;i<n;i++){
        if(a*i+b*(n-i)==w){
            if(!check){
                ans_a = i;
                ans_b = n-i;
            }
            check++;
        }
    }
    if(check==1) cout << ans_a << " " << ans_b;
    else cout << "-1";
}