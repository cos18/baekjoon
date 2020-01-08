#include <iostream>
#include <algorithm>
using namespace std;

int num[1000], N;
int up[1000]={}, down[1000]={};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num[i];
    }

    for(int i=0;i<N;i++){
        int tmp=1;
        for(int j=0;j<i;j++){
            if(num[j]<num[i]) tmp = max(tmp, up[j]+1);
        }
        up[i] = tmp;
    }
    for(int i=N-1;i>=0;i--){
        int tmp=1;
        for(int j=N-1;j>i;j--){
            if(num[j]<num[i]) tmp = max(tmp, down[j]+1);
        }
        down[i] = tmp;
    }

    int ans = 1;
    for(int i=0;i<N;i++){
        ans = max(ans, up[i]+down[i]-1);
    }

    cout << ans;

    return 0;
}
