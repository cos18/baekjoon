#include <iostream>
using namespace std;

long long save[100]={0, 1, };

long long fibo(int n){
    if(n!=0 && !save[n]) save[n] = fibo(n-1)+fibo(n-2);
    return save[n];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << fibo(n);
}