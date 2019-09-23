#include <iostream>
#include <vector>
using namespace std;

int N, check[100]={};
long long arrays[100], ans[100];

void go(int locate){
    if(locate==N){
        for(int i=0;i<N;i++){
            cout << ans[i] << " ";
        }
        exit(0);
    }
    for(int i=0;i<N;i++){
        if(check[i]) continue;
        if(locate){
            if(ans[locate-1]%3==0){
                if((ans[locate-1]*2!=arrays[i]) && (ans[locate-1]/3!=arrays[i])) continue;
            } else if(ans[locate-1]*2!=arrays[i]) continue;
        }
        check[i]=1;
        ans[locate] = arrays[i];
        go(locate+1);
        check[i]=0;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arrays[i];
    }
    go(0);
}