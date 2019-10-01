#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int map[10][10], N, M, fx, fy;
pair<int, int> spot[2]; // 0:RED, 1:BLUE

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int reversedir[4] = {1, 0, 3, 2};

bool move_ball(int direction, int ball){
    int x[2], y[2];
    tie(x[0], y[0]) = spot[0];
    tie(x[1], y[1]) = spot[1];
    if(map[x[ball]+dx[direction]][y[ball]+dy[direction]]==1) return false;
    while (true){
        x[ball]+=dx[direction];
        y[ball]+=dy[direction];
        if(x[ball]==x[1-ball] && y[ball]==y[1-ball]){
            if(x[1-ball]!=fx || y[1-ball]!=fy){
                x[ball]-=dx[direction];
                y[ball]-=dy[direction];
            }
            break;
        }
        if(map[x[ball]][y[ball]]==1){
            x[ball]-=dx[direction];
            y[ball]-=dy[direction];
            break;
        }
        if(map[x[ball]][y[ball]]==2) break;
    }
    spot[ball] = make_pair(x[ball], y[ball]);
    return true;
}

int go(int locate, int past){
    int ans = 11;
    if(spot[1].first==fx && spot[1].second==fy) return ans;
    if(spot[0].first==fx && spot[0].second==fy) return locate;
    if(locate==10) return ans;
    for(int i=0;i<4;i++){
        if(past>-1 && (past==i||reversedir[past]==i)) continue;
        int x1, x2, y1, y2;
        tie(x1, y1) = spot[0];
        tie(x2, y2) = spot[1];
        bool is_move = false;
        int start;
        switch(i){
            case 0:
            case 1:
                start=(x2>x1)?1-i:i;
                break;
            case 2:
            case 3:
                start=(y2>y1)?1-i/2:i/2;
        }
        is_move = is_move || move_ball(i, start);
        is_move = is_move || move_ball(i, 1-start);
        if(!is_move) continue;
        int tmp = go(locate+1, i);
        ans = (ans>tmp)?tmp:ans;
        move_ball(reversedir[i], 1-start);
        move_ball(reversedir[i], start);
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string tmp;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> tmp;
        for(int j=0;j<M;j++){
            switch(tmp[j]){
                case '#':
                    map[i][j]=1;
                    break;
                case 'R':
                case 'B':
                    spot[(tmp[j]=='R'?0:1)] = make_pair(i, j);
                case '.':
                    map[i][j]=0;
                    break;
                case 'O':
                    map[i][j]=2;
                    fx=i;fy=j;
                    break;
            }
        }
    }
    int ans = go(0, -1);
    cout << (ans==11?-1:ans);
}