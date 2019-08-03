#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, sosu[100001]={}, L=100000;
    for(int i=2;i*i<L;i++){
        if (sosu[i]) continue;
        for(int j=i*2;j<=L;j+=i) sosu[j]=1;
    }
    cin >> n;
    while(n--){
        cin >> a;
    }
    cout << (sosu[n]?"No":"Yes");
}