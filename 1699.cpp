#include <iostream>
using namespace std;
int check[100001]={};

int go(int n, int i){
    if(!check[n]){
        int now = 100000;
        for(int j = i;j*j<=n;j++){
            int checking = 1+go(n-j*j, j);
            now = (now>checking)?checking:now;
        }
        check[n]=now;
    }
    return check[n];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    for(int i=1;i*i<=100000;i++){
        check[i*i]=1;
    }
    cin >> N;
    cout << go(N, 1);
}