#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, wifi[200001]={};
vector<int> spot;

int go(long long cost, int locate){
    if(locate<0){
        for(int i=1;i<=n;i++){
            if(!wifi[i]) cost+=i;
        }
        return cost;
    }
    for(int i=max(1, spot[locate]-k);i<=min(n, spot[locate]+k);i++){
        wifi[i]++;
    }
    int ans = go(cost+spot[locate], locate-1);
    for(int i=max(1, spot[locate]-k);i<=min(n, spot[locate]+k);i++){
        wifi[i]--;
    }
    ans = min(ans, go(cost, locate-1));
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char a;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a;
        if(a=='1') spot.push_back(i);
    }
    cout << go(0, spot.size()-1);

}