#include <iostream>
using namespace std;
int check[1001]={};

int go(int n){
    if(!check[n]) check[n] = (go(n-1)+go(n-2))%10007;
    return check[n];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    check[1]=1;
    check[2]=2;
    cin >> N;
    cout << go(N);
}