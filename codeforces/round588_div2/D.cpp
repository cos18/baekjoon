#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

bool sorted(pair<long long, int> a, pair<long long, int> b){
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<pair<long long, int>> train;
    vector<pair<long long, int>> list;
    int n, b[7000];
    long long a[7000], max = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        list.push_back(make_pair(a[i], b[i]));
    }
    sort(list.begin(), list.end(), sorted);
    for(int i=0;i<n;i++){
        if(!train.empty()){
            while (true){
                long long algo;
                int stat, front_bestalgo=0;
                tie(algo, stat) = train.front();
                while(true){
                    if((1<<front_bestalgo)>algo) break;
                    front_bestalgo++;
                }
                front_bestalgo--;
                if(a[i] & (1<<front_bestalgo)) break;
                train.pop();
                if(train.empty()) break;
            }
        }
        train.push(list[i]);
        if(train.size()>1){
            long long tmp = 0;
            queue<pair<long long, int>> sum = train;
            while(!sum.empty()){
                tmp += sum.front().second;
                sum.pop();
            }
            max = (tmp>max)?tmp:max;
        }
    }
    cout << max;
}