#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int map[8][8]={}, M, N;
vector<vector<int>> direction{{}, {1}, {2}, {3}, {4}, {1, 3}, {2, 4}, {1, 4}, {1, 2}, {2, 3}, {3, 4}, {1, 3, 4}, {1, 2, 4}, {1, 2, 3}, {2, 3, 4}, {1, 2, 3, 4}};
int dx[5]={0, 0, 1, 0, -1};
int dy[5]={0, 1, 0, -1, 0};
vector<tuple<int, int, int>> cctvs;
vector<tuple<int, int, int>> locate_cctvs;

int watch(){
    int new_map[8][8], cnt=0;
    copy(&map[0][0], &map[0][0] + 64, &new_map[0][0]);
    for(int i=0;i<locate_cctvs.size();i++){
        int x, y, cctv;
        tie(x, y, cctv) = locate_cctvs[i];
        for(int j=0;j<direction[cctv].size();j++){
            int nx = x, ny = y;
            while(true){
                nx += dx[direction[cctv][j]];
                ny += dy[direction[cctv][j]];
                if(nx>=N || ny>=M || nx<0 || ny<0 || new_map[nx][ny]==16) break;
                if(new_map[nx][ny]==0){
                    new_map[nx][ny] = -1;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int locate(int cctv_cnt){
    if(cctv_cnt==cctvs.size()){
        return watch();
    }
    int max = 0, x, y, cctv, redo;
    tie(x, y, cctv) = cctvs[cctv_cnt];
    switch(cctv){
        case 1:
        case 7:
        case 11:
            redo = 4; break;
        case 5:
            redo = 2; break;
        case 15:
            redo = 1; break;
    }
    for(int i=0;i<redo;i++){
        locate_cctvs.emplace_back(x, y, cctv+i);
        int watch = locate(cctv_cnt+1);
        max = watch>max?watch:max;
        locate_cctvs.pop_back();
    }
    return max;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int zeros = 0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            switch (map[i][j]){
                case 0:
                    zeros++; break;
                case 2:
                    map[i][j] = 5; break;
                case 3:
                    map[i][j] = 7; break;
                case 4:
                    map[i][j] = 11; break;
                case 5:
                    map[i][j] = 15; break;
                case 6:
                    map[i][j] = 16; break;
            }
            if(map[i][j]>0 && map[i][j]<16){
                cctvs.emplace_back(i, j, map[i][j]);
            }
        }
    }
    cout << zeros-locate(0);
}