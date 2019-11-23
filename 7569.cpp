#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, H, tleft=0, bleft=0;
    int map[100][100][100]={};
    queue<pair<tuple<int, int, int>, int>> rotten;
    cin >> M >> N >> H;
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                cin >> map[j][k][i];
                switch (map[j][k][i]) {
                    case 1:
                        rotten.emplace(make_tuple(j, k, i), 0);
                        break;
                    case 0:
                        tleft++;
                    case -1:
                        bleft++;
                }
            }
        }
    }
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dh[6] = { 0, 0, 0, 0, 1, -1};
    int now=0;
    while(!rotten.empty()){
        int nx, ny, nh;
        now = rotten.front().second;
        tie(nx, ny, nh) = rotten.front().first;
        rotten.pop();
        for(int i=0;i<6;i++){
            int fx = nx+dx[i], fy=ny+dy[i], fh=nh+dh[i];
            if(fx<0 || fy<0 || fh<0 || fx>=N || fy>=M || fh>=H) continue;
            if(map[fx][fy][fh]!=0) continue;
            map[fx][fy][fh]=1;
            tleft--;
            rotten.emplace(make_tuple(fx, fy, fh), now+1);
        }
    }
    cout << ((bleft==N*M*H)?-1:((tleft)?-1:now));
}