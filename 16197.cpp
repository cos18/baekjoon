#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int map[20][20], N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int,int>> coins;

bool outofrange(int x, int y){
    return (x < 0 || x >= N) || (y < 0 || y >= M);
}

int go(int times){
    if(times>10) return 11;
    int ans = 11;
    int x1, y1, x2, y2;
    tie(x1, y1) = coins[0];
    tie(x2, y2) = coins[1];
    int nx1, ny1, nx2, ny2;
    for(int i=0;i<4;i++){
        nx1 = x1+dx[i];
        ny1 = y1+dy[i];
        nx2 = x2+dx[i];
        ny2 = y2+dy[i];
        bool p1 = outofrange(nx1, ny1);
        bool p2 = outofrange(nx2, ny2);
        if((p1||p2)&&(!p1 || !p2)) return times;
        if(map[nx1][ny1] && map[nx2][ny2] || (p1&&p2)) continue;
        coins.clear();
        if(map[nx1][ny1]==1) coins.push_back(make_pair(x1, y1));
        else coins.push_back(make_pair(nx1, ny1));
        if(map[nx2][ny2]==1) coins.push_back(make_pair(x2, y2));
        else coins.push_back(make_pair(nx2, ny2));
        int tmp = go(times+1);
        ans = ans>tmp?tmp:ans;
    }
    coins.clear();
    coins.push_back(make_pair(x1, y1));
    coins.push_back(make_pair(x2, y2));
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    string tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        for(int j=0;j<M;j++){
            switch(tmp[j]){
                case 'o':
                    coins.push_back(make_pair(i, j));
                case '.':
                    map[i][j]=0;
                    break;
                case '#':
                    map[i][j]=1;
                    break;
            }
        }
    }
    int ans = go(1);

    cout << (ans==11?-1:ans);
}