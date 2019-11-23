#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> path[100001];
int N, parent[100001]={}, depth[100001]={}, p[100001][17], len[100001]={}; // root : depth 0
bool check[100001]={};

void check_level(int locate, int l){
    depth[locate] = l;
    check[locate] = true;
    for(auto p : path[locate]){
        int n = p.first;
        if(check[n]) continue;
        parent[n] = locate;
        check_level(n, l+1);
    }
}

int fill_len(int a){
    if(a==1) return 0;
    if(len[a]==0){
        int plen;
        for(auto p : path[a]){
            if(p.first==parent[a]){
                plen=p.second;
                break;
            }
        }
        len[a] = fill_len(parent[a]) + plen;
    }
    return len[a];
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
        int a, b, c;
        cin >> a >> b >> c;
        path[a].emplace_back(b, c);
        path[b].emplace_back(a, c);
    }
    parent[0]=-1;
    check_level(1, 0);
    for(int i=N;i>0;i--){
        if(!len[i]) fill_len(i);
    }
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
        cout << len[a] + len[b] - 2*len[lca(a, b)] << '\n';
    }
}