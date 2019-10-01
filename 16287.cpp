#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int w, n, a[5000];
vector<int> twosum[400000];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> w >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            twosum[a[i]+a[j]].push_back(a[i]);
        }
    }
    for(int i=3;i<400000;i++){
        int target = w-i;
        if(target>=400000) continue;
        if(!twosum[i].empty() && !twosum[target].empty()){
            if(twosum[i].size()>2 || twosum[target].size()>2){
                cout << "YES";
                return 0;
            }
            for(int j : twosum[target]){
                int x=target-j;
                for(int k : twosum[i]){
                    int y=i-k;
                    if(x!=k && x!=y && j!=y && j!=k){
                        cout << "YES";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}