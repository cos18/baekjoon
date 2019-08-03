#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> jhosep;
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        jhosep.push(i);
    }
    cout << "<";
    while(!jhosep.empty()){
        for(int i=0;i<k-1;i++){
            jhosep.push(jhosep.front());
            jhosep.pop();
        }
        cout << jhosep.front();
        jhosep.pop();
        cout << ((jhosep.empty())?">\n":", ");
    }
    return 0;
}
