#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int map[100][100] = {}, N, K, L, rotate[100][2];
    deque<pair<int, int>> snake;
    int dx[4]={0, 1, 0, -1};
    int dy[4]={1, 0, -1, 0};

    cin >> N >> K;
    int x, y;
    for(int i=0;i<K;i++){
        cin >> x >> y;
        map[x-1][y-1] = 1;
    }
    snake.emplace_front(0, 0);
    map[0][0] = 2;

    cin >> L;
    char c;
    for(int i=0;i<L;i++){
        cin >> x >> c;
        rotate[i][0]=x;
        rotate[i][1] = ((c=='D')?1:-1);
    }

    int time = 0, dir = 0, locate = 0;
    while (true){
        time++;
        tie(x, y) = snake.front();
        x+=dx[dir]; y+=dy[dir];
        if(x<0 || y<0 || x>=N || y>=N) break;
        if(map[x][y]==2) break;
        snake.emplace_front(x, y);

        if(map[x][y]==0){
            int lx, ly;
            tie(lx, ly) = snake.back();
            map[lx][ly] = 0;
            snake.pop_back();
        }
        map[x][y] = 2;

        if(time==rotate[locate][0]){
            dir += rotate[locate++][1];
            switch(dir){
                case -1:
                    dir = 3;
                    break;
                case 4:
                    dir = 0;
                    break;
            }
        }
    }

    cout << time;

    return 0;
}
