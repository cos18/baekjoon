#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;

    int N, tmp;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    bool h = prev_permutation(v.begin(),v.end());
    if(h){
        for(int i=0; i<N; i++){
            cout << v[i] << " ";
        }
    } else cout << -1;


    return 0;

}