#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, arr[1000], cnt[1000]={};
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    for(int i=0;i<N;i++){
        cnt[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && cnt[j]+1>cnt[i]){
                cnt[i] = cnt[j]+1;
            }
        }
    }
    sort(cnt, cnt+N);
    cout << cnt[N-1];
}