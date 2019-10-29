#include <iostream>
#include <set>

using namespace std;

int pan[5][5];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
set<int> nums;

void go(int x, int y, int cnt, int now){
    if(x<0 || y<0 || x>4 || y>4) return;
    now = now*10+pan[x][y];
    if(cnt>4){
        nums.insert(now);
        return;
    }
    for(int i=0;i<4;i++){
        go(x+dx[i], y+dy[i], cnt+1, now);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(auto & i : pan){
        for(int & j : i){
            cin >> j;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            go(i, j, 0, 0);
        }
    }
    cout << nums.size();
}