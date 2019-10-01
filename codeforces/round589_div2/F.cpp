#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> edge[131100];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    vector<int> check;
    cin >> n;
    if(n==2){
        cout << "2\n1 2";
        return 0;
    }
    int edges = pow(2, n)-3;
    for(int i=0;i<edges;i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=edges+2;i++){
        if(edge[i].size()==4){
            cout << "1\n" << i;
            return 0;
        }
        if(edge[i].size()==2){
            check.push_back(i);
        }
    }
    for(int i : check){
        for(int j : edge[i]){
            if(edge[j].empty()){
                cout << "1\n" << i;
                return 0;
            }
        }
    }
    cout << 0;
}