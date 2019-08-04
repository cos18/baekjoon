#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, in, max = 0;
    cin >> N;
    while(N--){
        cin >> in;
        if(in>max){
            max = in;
        }
    }
    cout << max;
}