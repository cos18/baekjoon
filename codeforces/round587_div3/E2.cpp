#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long count_num[10000001]={};

// TODO : K <= 2e18의 경우 해봐야 함.

int zarisu(long long a){
    if(a<10) return 1;
    return 1+zarisu(a/10);
}

int find(long long a, int zari){
    if(zari==0) return a%10;
    return find(a/10, zari-1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=1;i<10000001;i++){
        count_num[i] = count_num[i-1] + zarisu(i);
    }

    long long q, k;
    cin >> q;
    while(q--){
        cin >> k;
        int locate=1;
        while(true){
            if(k<=count_num[locate]) break;
            k-=count_num[locate++];
        }
        int final=1;
        int tmp;
        while(true){
            tmp = zarisu(final);
            if(k<=tmp) break;
            k-=tmp;
            final++;
        }
        cout << find(final, tmp-k) << '\n';
    }
}