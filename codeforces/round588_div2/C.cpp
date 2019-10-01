#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m, domino[8]={}, first=8;
vector<int> graph[8];


int go(int locate){
    if(locate==8){
        int check[22]={}, cnt=0;
        for(int i=1;i<=7;i++){
            int idomino = domino[i];
            int k=7-idomino;
            int checknum = 21-k*(k+1)/2;
            for(int j=0;j<graph[i].size();j++){
                int jdomino = domino[graph[i][j]];
                if(jdomino>=idomino){
                    if(!check[checknum+jdomino-idomino+1]){
                        check[checknum+jdomino-idomino+1]=1;
                        cnt++;
                    }
                }
            }
        }
        return cnt;

    }
    int max = 0;
    for(int i=1;i<=6;i++){
        domino[locate] = i;
        int tmp = go(locate+1);
        max = (max<tmp)?tmp:max;
    }
    return max;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    if(n!=7 || m<2){
        cout << m;
        return 0;
    }

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        first = (u>first)?first:u;
    }

    cout << go(1);
}