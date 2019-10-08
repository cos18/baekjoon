#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, mul;
    cin >> a >> b;
    if(a<b){
        a^=b;
        b^=a;
        a^=b;
    }
    mul = a*b;
    while(b!=0){
        int tmp = a%b;
        a = b;
        b=tmp;
    }
    cout << a << endl << mul/a;
}