#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int count_num[1000001]={}, sum_num[1000001]={};

int zarisu(int a){
    if(a<10) return 1;
    return 1+zarisu(a/10);
}

int find(int a, int zari){
    if(zari==0) return a%10;
    return find(a/10, zari-1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=1;i<1000001;i++){
        count_num[i] = count_num[i-1] + zarisu(i);
    }

    int q, k;
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