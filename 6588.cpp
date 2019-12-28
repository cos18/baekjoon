#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int check[1000001]={};
    vector<int> sosu;
    for(int i=2;i*i<=1000000;i++){
        if(check[i]) continue;
        sosu.push_back(i);
        for(int j=i*i;j<=1000000;j+=i){
            check[j] = 1;
        }
    }

    while(true){
        int now;
        cin >> now;
        if(!now) break;
        for(int i=3;i<=500000;i++) {
            if (i == 2) continue;
            if (i * 2 > now) {
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }
            if (!check[i] && !check[now - i]) {
                cout << now << " = " << i << " + " << now - i << "\n";
                break;
            }
        }
    }
}