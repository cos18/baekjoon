#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long num = 0;
    int N, count = 9;
    cin >> N;
    while(true){
        if(count>=N){
            num += N * (log10(count/9) + 1);
            break;
        }
        num += count * (log10(count/9) + 1);
        N -= count;
        count *= 10;
    }
    cout << num;
}