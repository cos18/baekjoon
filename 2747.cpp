#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, save[50]={0, 1, };
    for(int i=2;i<=45;i++) save[i] = save[i-1]+save[i-2];
    cin >> n;
    cout << save[n];
}