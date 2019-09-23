#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b){
    return a > b;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, tmp;
    vector<pair<int, int>> a;
    vector<int> l;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> tmp;
        a.push_back(make_pair(tmp, i));
    }
    sort(a.begin(), a.end(), desc);
    int total=0;
    for(int i=0;i<N;i++){
        total += i*(a[i].first) + 1;
        l.push_back(a[i].second);
    }
    cout << total << "\n";
    for(int i=0;i<N;i++){
        cout << l[i];
        if(i!=N-1) cout << " ";
    }
}