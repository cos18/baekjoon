#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a[11], fun[4], locate_fun[11];

vector<int> results;

void go(int locate){
    if(locate==N-1){
        int result = a[0];
        for(int i=0;i<N-1;i++){
            switch(locate_fun[i]){
                case 0:
                    result += a[i+1]; break;
                case 1:
                    result -= a[i+1]; break;
                case 2:
                    result *= a[i+1]; break;
                case 3:
                    result /= a[i+1]; break;
            }
        }
        results.push_back(result);
        return;
    }
    for(int i=0;i<4;i++){
        if(!fun[i]) continue;
        fun[i]--;
        locate_fun[locate] = i;
        go(locate+1);
        fun[i]++;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<4;i++){
        cin >> fun[i];
    }
    go(0);
    sort(results.begin(), results.end());
    cout << results[results.size()-1] << "\n" << results[0] << "\n";
}