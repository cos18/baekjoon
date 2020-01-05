#include <iostream>
#include <vector>

using namespace std;
vector<int> cost;

void go(int locate, int N){
    for(int i=1;i<=N;i++){

    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int total[1001]={}, N, tmp;
    cost.push_back(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        cost.push_back(tmp);
    }

    for(int i=0;i<N;i++){
        for(int j=1;i+j<=N;j++){
            total[i+j] = max(total[i+j], total[i]+cost[j]);
        }
    }

    cout << total[N];
    return 0;
}
