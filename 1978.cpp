#include <iostream>
using namespace std;

int main() {
    int m, n, sosu[1000001]={1, 1, }, L=1000000;
    for(int i=2;i*i<L;i++){
        if (sosu[i]) continue;
        for(int j=i*i;j<=L;j+=i) sosu[j]=1;
    }
    cin >> m >> n;
    for(int i=m;i<=n;i++) {
        if (!sosu[i]) cout << i << "\n";
    }
}

