#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (true){
        cin >> n;
        if(cin.eof()) break;
        int cnt = 1, test = 1;
        while(test%n!=0){
            cnt++;
            test = ((test*10)%n+1)%n;
        }
        cout << cnt << "\n";
    }
}