#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100111;
vector<int> path[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];
int p[MAX][17];
int n, x, y, embpath[100000];

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u,v);
    }
    int log = 1;
    for (log=1; (1<<log) <= depth[u]; log++);
    log-=1;
    for (int i=log; i>=0; i--) {
        if (depth[u] - (1<<i) >= depth[v]) {
            u = p[u][i];
        }
    }
    if (u == v) {
        return u;
    } else {
        for (int i=log; i>=0; i--) {
            if (p[u][i] != 0 && p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return parent[u];
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        cin >> embpath[i];
    }
    depth[1] = 0;
    check[1] = true;
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : path[x]) {
            if (!check[y]) {
                depth[y] = depth[x] + 1;
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        p[i][0] = parent[i];
    }
    for (int j=1; (1<<j) < n; j++) {
        for (int i=1; i<=n; i++) {
            if (p[i][j-1] != 0) {
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int len = depth[embpath[i]]+depth[embpath[i+1]]-2*depth[lca(embpath[i], embpath[i+1])];
        ans = (ans<len)?len:ans;
        if(ans>3) break;
    }
    cout << ((ans>3)?99:ans);
}