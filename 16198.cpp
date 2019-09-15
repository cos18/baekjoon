#include <iostream>
using namespace std;

int N, W[10], save[9], check[9]={};

int find_max(int locate){
    int max = 0;
    if(N-2==locate){
        int cal[10]={};
        for(int i=0;i<N-2;i++){
            int left = save[i]-1, right = save[i]+1;
            while(cal[left]) left--;
            while(cal[right]) right++;
            max += W[left]*W[right];
            cal[save[i]] = 1;
        }
    } else {
        for(int i=1;i<9;i++){
            if(check[i]) continue;
            check[i]=1;
            save[locate] = i;
            int tmp = find_max(locate+1);
            max = max>tmp?max:tmp;
            check[i]=0;
        }
    }
    return max;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> W[i];
    }
    cout << find_max(0);
}