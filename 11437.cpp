#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> path[100001];
int N, parent[100001]={}, depth[100001]={}, p[100001][17]; // root : depth 0
bool check[100001]={};

void check_level(int locate, int l){
    depth[locate] = l;
    check[locate] = true;
    for(int n : path[locate]){
        if(check[n]) continue;
        parent[n] = locate;
        check_level(n, l+1);
    }
}

int lca(int a, int b){
    if(depth[a]<depth[b]){
        swap(a, b);
    }
    int log = 1;
    for(;(1<<log)<=depth[a];log++);
    log-=1;
    for(int i=log;i>=0;i--){
        if(depth[a]-(1<<i) >= depth[b]) a = p[a][i];
    }
    if(a==b) return a;
    else{
        for(int i=log;i>=0;i--){
            if(p[a][i]!=0 && p[a][i] != p[b][i]){
                a = p[a][i];
                b = p[b][i];
            }
        }
        return parent[a];
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<N;i++){
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    parent[0]=-1;
    check_level(1, 0);
    for (int i=1; i<=N; i++) p[i][0] = parent[i];
    for (int j=1; (1<<j) < N; j++) {
        for (int i=1; i<=N; i++) {
            if (p[i][j-1] != 0) p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}