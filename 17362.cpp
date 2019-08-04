#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    switch (n%8){
        case 1:
            cout << 1;
            break;
        case 2:
        case 0:
            cout << 2;
            break;
        case 3:
        case 7:
            cout << 3;
            break;
        case 4:
        case 6:
            cout << 4;
            break;
        default:
            cout << 5;
            break;
    }
}