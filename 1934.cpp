#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a<b) swap(a, b);
    if (b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int T;
    cin >> T;
    while (T--){
        int a, b;
        cin >> a >> b;
        cout << a*b/gcd(a,b) << endl;
    }
}