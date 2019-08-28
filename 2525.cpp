#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    M += K;
    if(M>=60){
        N += M/60;
        M %= 60;
    }
    if(N>=24){
        N %= 24;
    }
    cout << N << " " << M;
}