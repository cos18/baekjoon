#include <iostream>
#include <algorithm>
using namespace std;

int check[9]={}, kg[9];

void go(int locate, int checkcnt){
    if(locate==9){
        int sum=0;
        for(int i=0;i<9;i++){
            if(check[i]) sum += kg[i];
        }
        if(sum!=100) return;
        for(int i=0;i<9;i++){
            if(check[i]) cout << kg[i] << "\n";
        }
        exit(0);
    }
    if(checkcnt<7){
        check[locate] = 1;
        go(locate+1, checkcnt+1);
    }
    check[locate] = 0;
    go(locate+1, checkcnt);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<9;i++){
        cin >> kg[i];
    }
    sort(kg, kg+9);
    go(0, 0);
}