#include <iostream>
#include <cmath>

using namespace std;

long long powl(int n){
    if (n==1) return 2;
    return 2*powl(n-1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k=1;
    cin >> n;
    while (true){
        long long num = k+(k+1)*(powl(k+1)-1);
        if(n<=num) break;
        k++;
    }
    cout << k;
}