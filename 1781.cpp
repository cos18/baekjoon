#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair<int, long long> cups[200001];
    priority_queue<long long> left;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> cups[i].first >> cups[i].second;
    }
    sort(cups, cups+N);
    for(int i=0;i<N;i++){
        int limit = cups[i].first;
        left.push(-cups[i].second);
        while(limit<left.size()) left.pop();
    }
    long long ans=0;
    while(!left.empty()){
        ans -= left.top();
        left.pop();
    }
    cout << ans;
}