#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<long long> num;
    long long sum = 0, N;
    cin >> N;
    num.resize(N);
    for(long long i=0;i<N;i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    for(long long i=0;i<N;i++){
        sum += abs(num[i]-(i+1));
    }
    cout << sum;
}