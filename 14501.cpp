#include <iostream>
#include <algorithm>
using namespace std;

int N, T[15], P[15];

int go(int day, int pay){
    if(day>N) return 0;
    if(day==N) return pay;
    return max(go(day+1, pay), go(day+T[day], pay+P[day]));
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> T[i] >> P[i];
    }
    cout << go(0, 0);
}