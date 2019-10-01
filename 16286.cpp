#include <iostream>
#include <cstring>
using namespace std;

int W, N, weight[500000]={};

int dp[500000];

bool isOk(int end, int target){
    if (dp[end]!=-1) return dp[end]==1;
    if(!end){
        dp[end] = (target >= weight[end])?1:0;
        return dp[end]==1;
    }
    int sum=0;
    for(int i=end-1;i>=0;i--){
        sum+=weight[i];
        if((target>=sum) && isOk(i, target)){
            dp[end] = 1;
            return true;
        }
    }
    dp[end] = 0;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> W >> N;
    for(int i=0;i<N;i++){
        cin >> weight[i];
        cout << "hello";
    }
    cout << "hello";
    int left=0, right=W, mid;
    cout << "hello";
    while (true){
        if(left==right) break;
        mid = (left + right) / 2;
        memset(dp, -1, sizeof(dp));
        if(isOk(N-1, mid))left=mid;
        else right=mid-1;
    }
    cout << W-mid;
}