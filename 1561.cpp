#include <iostream>
using namespace std;

int ride[10000];
long long N, M;

long long cal(long long num){
    long long ans = M;
    for(int i=0;i<M;i++){
        ans += num/ride[i];
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    for (int i=0; i<N; i++) {
        cin >> ride[i];
    }
    if (M <= N) {
        cout << M;
        return 0;
    }
    long long left = 0;
    long long right = 2000000000LL * 300000LL;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long begin, end;
        begin = end = 0;
        end = N;
        for (int i=0; i<N; i++) {
            end += mid/ride[i];
        }
        begin = end;
        for (int i=0; i<N; i++) {
            if (mid % ride[i] == 0) {
                begin--;
            }
        }
        begin += 1;
        if (M < begin) {
            right = mid-1;
        } else if (M > end) {
            left = mid+1;
        } else {
            for (int i=0; i<N; i++) {
                if (mid % ride[i] == 0) {
                    if (M == begin) {
                        cout << i+1;
                        return 0;
                    }
                    begin++;
                }
            }
        }
    }
    return 0;

}