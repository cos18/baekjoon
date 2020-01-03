#include <iostream>
#include <vector>
using namespace std;

int safe[13];
vector<pair<int, int>> home, chicken;
int N, M;

int cal(){
    int len = 0;
    for(auto h : home){
        int m = 2*N;
        for(int i=0;i<chicken.size();i++){
            if(!safe[i]) continue;
            m = min(m, abs(h.first-chicken[i].first) + abs(h.second-chicken[i].second));
        }
        len += m;
    }
    return len;
}

int go(int locate, int check){
    if(locate==chicken.size()){
        if(check==M) return cal();
        return 4*N*N;
    }
    int tmp = 4*N*N;
    if(check<M){
        safe[locate] = 1;
        tmp = min(go(locate+1, check+1), tmp);
    }
    safe[locate] = 0;
    tmp = min(tmp, go(locate+1, check));
    return tmp;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int tmp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> tmp;
            switch(tmp) {
                case 1:
                    home.emplace_back(i, j);
                    break;
                case 2:
                    chicken.emplace_back(i, j);
            }
        }
    }

    cout << go(0, 0) << '\n';

    return 0;
}
