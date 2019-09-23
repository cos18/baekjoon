#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<bool> sosu(N+1);
    vector<int> snum;
    for(int i=2;i<=N;i++){
        if (sosu[i]) continue;
        for(int j=i*2;j<=N;j+=i) sosu[j]=true;
        snum.push_back(i);
    }
    int i=0, j=0, sum=2, cnt=0;
    if(N<=2){
        cout << N-1;
        return 0;
    }
    while(i<=j && j<snum.size()){
        if(sum<=N){
            if(sum==N) cnt++;
            j++;
            if (j<snum.size()) sum+=snum[j];
        } else sum -= snum[i++];
    }
    cout << cnt;
}