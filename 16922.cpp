#include <iostream>
using namespace std;

int N, check[1001]={}, roma[4] = {1, 5, 10, 50};

int go(int locate, int start, int sum){
    if (locate==N){
        if(check[sum]) return 0;
        check[sum]=1;
        return 1;
    }
    int ans = 0;
    for(int i=start;i<4;i++){
        ans += go(locate+1, i, sum+roma[i]);
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cout << go(0, 0, 0);
}