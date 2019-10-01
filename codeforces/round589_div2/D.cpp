#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[100001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b;
    vector<int> check(100001);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i : edge[1]){
        check[i]=2;
    }
    check[1]=1;
    for(int i=2;i<=n;i++){
        if(check[i]) continue;
        vector<int> newcheck(check);
        for(int j:edge[i]){
            newcheck[j]-=2;
        }
        for(int j=2;j<=n;j++) {
            if(newcheck[j]==-1 || newcheck[j]==2 || newcheck[j]==-2){
                cout << -1;
                return 0;
            }
        }
        check[i]=1;
    }
    int third = 1;
    while(true){
        if(check[++third]!=1) break;
    }
    for(int i : edge[third]){
        check[i]=3;
    }
    check[third]=3;
    for(int i=2;i<=n;i++){
        if(check[i]!=2) continue;
        vector<int> newcheck(check);
        for(int j:edge[i]){
            newcheck[j]-=3;
        }
        for(int j=2;j<=n;j++) {
            if(newcheck[j]<0){
                cout << -1;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << check[i] << " ";
    }
}