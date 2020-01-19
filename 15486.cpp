#include <iostream>
using namespace std;

int N, t[1500002], p[1500002];
long long total[1500002]={};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> t[i] >> p[i];
    }

    for (int i = N; i >= 1; i--){
        if (i + t[i] > N + 1){
            total[i] = total[i + 1];
        } else{
            total[i] = max(total[i+1], p[i]+total[i+t[i]]);
        }
    }

    cout << total[1];

    return 0;
}
