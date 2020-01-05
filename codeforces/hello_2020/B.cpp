#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool is_ascent[100000];
    int n, first=0;
    vector<int> fv, lv;
    cin >> n;
    for(int i=0;i<n;i++){
        int len, ttmp, check = 1000001;
        vector<int> tmp;
        cin >> len;
        for(int j=0;j<len;j++){
            cin >> ttmp;
            tmp.push_back(ttmp);
            if(check>=ttmp) check=ttmp;
            else{
                is_ascent[i] = true;
                first++;
            }
        }
        if(!is_ascent[i]){
            fv.push_back(tmp[0]);
            lv.push_back(tmp[tmp.size()-1]);
        }
    }

    sort(fv.begin(), fv.end());
    sort(lv.begin(), lv.end());
    int fv_size = fv.size();
    long long final=0;

    for(int l : lv){
        int ans = lower_bound(fv.begin(), fv.end(), l+1)-fv.begin();
        final += (fv_size-ans);
        final += first;
    }

    for(int i=0;i<n;i++){
        final += first;
    }
    cout << final << '\n';

    return 0;
}
