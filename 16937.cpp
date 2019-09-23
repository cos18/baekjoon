#include <iostream>
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
        int iRH = H-R[i], iCH = H-C[i], iRW = W-R[i], iCW = W-C[i];
        for(int j=i+1;j<N;j++){
            if(((R[i]+R[j] <= H) && (C[i]+C[j] <= W)) || ((R[i]+C[j] <= H) && (C[i]+R[j] <= W)) || ((C[i]+R[j] <= H) && (R[i]+C[j] <= W)) || ((C[i]+C[j] <= H) && (R[i]+R[j] <= W))){
                ans = (size[i]+size[j]>ans)?(size[i]+size[j]):ans;
            } else if ((R[j]<=H && C[j]<=iCW) || (C[j]<=H && R[j]<=iCW) || (R[j]<=iRH && C[j]<=W) || (C[j]<=iRH && R[j]<=W)){
                ans = (size[i]+size[j]>ans)?(size[i]+size[j]):ans;
            } else if ((R[j]<=H && C[j]<=iRW) || (C[j]<=H && R[j]<=iRW) || (R[j]<=iCH && C[j]<=W) || (C[j]<=iCH && R[j]<=W)){
                ans = (size[i]+size[j]>ans)?(size[i]+size[j]):ans;
            }
        }
    }
    cout << ans;
}