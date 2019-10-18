#include <iostream>

using namespace std;

string pass;
int check[20], allocate[20];

int go(int locate, int m){
    if(locate==m){
        int strlong = pass.size();
        for(int i=0;i<strlong;)
    }
    for(int i=0;i<m;i++){
        if(check[i]) continue;
        check[i]=1;
        allocate[locate] = i;
        go(locate+1, m);
        check[i]=0;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    cin >> pass;
    cout << go();
}