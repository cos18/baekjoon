#include <iostream>
#include <algorithm>
using namespace std;

int make1[1000001]={};

int go(int n){
    if(n!=1 && make1[n]==0){
        make1[n] = go(n-1)+1;
        if(n%2==0){
            make1[n] = min(make1[n], go(n/2)+1);
        }
        if(n%3==0){
            make1[n] = min(make1[n], go(n/3)+1);
        }
    }
    return make1[n];

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << go(n);
}