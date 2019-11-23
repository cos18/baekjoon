#include <iostream>
#include <queue>

using namespace std;

char map[12][6];

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin >> map[i][j];
        }
    }
    int answer=0;
    while(true){
        int x=0, y=0;
        bool is_yeonse=false;
        bool check[12][6]={};
        while(true){
            while(true){
                if(map[x][y]!='.' && !check[x][y]) break;
                if(++y==6){
                    y=0; x++;
                }
                if(x==12) break;
            }
            if(x==12) break;
            vector<pair<int, int>> q;
            int locate=0;
            q.emplace_back(x, y);
            check[x][y]=true;
            while(q.size()>locate){
                int nx=q[locate].first;
                int ny=q[locate].second;
                for(int i=0;i<4;i++){
                    int fx=nx+dx[i], fy=ny+dy[i];
                    if(fx<0||fy<0||fx>=12||fy>=6) continue;
                    if(check[fx][fy] || map[fx][fy]!=map[nx][ny]) continue;
                    check[fx][fy]=true;
                    q.emplace_back(fx, fy);
                }
                locate++;
            }
            if(q.size()>=4){
                for(auto p : q) map[p.first][p.second]='.';
                is_yeonse=true;
            }
        }
        if(!is_yeonse) break;
        answer++;
        for(int i=0;i<6;i++){
            vector<char> color;
            for(int j=11;j>=0;j--){
                if(map[j][i]!='.') color.push_back(map[j][i]);
            }
            for(int j=0;j<12;j++){
                if(color.size()>j) map[11-j][i] = color[j];
                else map[11-j][i] = '.';
            }
        }
    }
    cout << answer;
}