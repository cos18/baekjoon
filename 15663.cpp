#include <iostream>
#include <algorithm>
using namespace std;
int N, M, num[8], cnt[8]={}, ans[8];

void go(int locate, int total){
    if(M==locate){
        for(int i=0;i<M;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0;i<total;i++){
        if(!cnt[i]) continue;
        ans[locate] = num[i];
        cnt[i]--;
        go(locate+1, total);
        cnt[i]++;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
    sort(num, num+N);
    int locate=0;
    for(int i=0;i<N;i++){
        if(i && num[i-1]!=num[i]){
            num[++locate] = num[i];
        }
        cnt[locate]++;
    }
    go(0, locate+1);
}