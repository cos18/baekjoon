#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W, N, R[100], C[100], size[100];
    cin >> H >> W >> N;
    for(int i=0;i<N;i++){
        cin >> R[i] >> C[i];
        size[i] = R[i] * C[i];
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        int r1 = R[i], c1 = C[i];
        for(int j=i+1;j<N;j++){
            int r2 = R[j], c2 = C[j];
            for (int rot1=0; rot1<2; rot1++) {
                for (int rot2=0; rot2<2; rot2++) {
                    if (r1+r2 <= H && max(c1,c2) <= W) {
                        ans = max(ans, size[i]+size[j]);
                    }
                    if (max(r1,r2) <= H && c1+c2 <= W) {
                        ans = max(ans, size[i]+size[j]);
                    }
                    swap(r2, c2);
                }
                swap(r1, c1);
            }
        }
    }
    cout << ans;
}