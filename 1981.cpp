#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

int N, map[100][100];
int mmax = 0, mmin=200;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(int min, int max){
    if (min > map[0][0] || max < map[0][0]) {
        return false;
    }
    queue<pair<int, int>> q;
    bool check[100][100]={};
    q.push(make_pair(0, 0));
    check[0][0]=true;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N || check[nx][ny]) continue;
            if(min > map[nx][ny] || max < map[nx][ny]) continue;
            check[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    return check[N-1][N-1];
}

bool go(int d) {
    for (int i=mmin; i+d<=mmax; i++) {
        if (bfs(i, i+d)) {
            return true;
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            mmax = MAX(map[i][j], mmax);
            mmin = MIN(map[i][j], mmin);
        }
    }
    int smin = 0, smax = mmax-mmin;
    int answer = smax;
    while(smin<=smax){
        int target = (smin+smax)/2;

        if(go(target)){
            answer = MIN(target, answer);
            smax = target-1;
        } else smin = target+1;
    }
    cout << answer;
}