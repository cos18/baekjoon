#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_MIN -1000000000

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, tmp, psize=0, msize=0;
    bool is_zero=false;
    vector<int> plus, minus;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        if(tmp>0){
            plus.push_back(tmp);
            psize++;
        } else if (tmp<0){
            minus.push_back(tmp);
            msize++;
        } else is_zero = true;
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    int ans = MAX_MIN;
    if(msize>=2){
        ans = max(ans, minus[0]*minus[1]);
        if(psize>=1) ans = max(ans, minus[0]*minus[1]*plus[psize-1]);
    }
    if(psize>=2) ans = max(ans, plus[psize-1]*plus[psize-2]);
    if(psize>=3) ans = max(ans, plus[psize-1]*plus[psize-2]*plus[psize-3]);
    if(ans==MAX_MIN && is_zero) ans = 0;
    cout << ans;
}