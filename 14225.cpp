#include <iostream>
#include <algorithm>
using namespace std;

int N,s[20], check[2000001]={};

void check_sum(int locate, int sum){
    if(locate==N){
        check[sum]=1;
        return;
    }
    check_sum(locate+1, sum+s[locate]);
    check_sum(locate+1, sum);
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int lost=1;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s[i];
    }
    check_sum(0, 0);
    while(true){
        if(!check[lost++]) break;
    }
    cout << lost-1;
}