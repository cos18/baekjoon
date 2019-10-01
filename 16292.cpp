#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
long long v, e, s, x, y, z, d[3][20002];
// s : start vertex
vector<vector<pair<long long, long long>>> vt;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    vt.resize(v + 1);
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> z;
        vt[x].push_back({ y,z });
        vt[y].push_back({ x,z });
    }
    for(int i=0;i<3;i++){
        cin >> s;
        for(int j=1;j<=v;j++){
            d[i][j] = -1;
        }
        priority_queue<pair<long long, long long>> pq;
        pq.push({ 0,s });
        while (pq.size()) {
            long long here = pq.top().second;
            long long cost = -pq.top().first;
            pq.pop();
            if (d[i][here] != -1)
                continue;
            d[i][here] = cost;
            for (auto it : vt[here]) {
                long long next = it.first;
                long long acost = -it.second - cost;
                if (d[i][next] != -1)
                    continue;
                pq.push({ acost,next });
            }
        }
    }

    long long min = 10000*100000;

    for (int i = 1; i <= v; i++) {
        long long sum = d[0][i];
        sum = (sum>d[1][i])?sum:d[1][i];
        sum = (sum>d[2][i])?sum:d[2][i];
        min = (min>sum)?sum:min;
    }
    cout << min;
    return 0;
}