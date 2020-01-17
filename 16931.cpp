#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 코딩중


    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, block[100][100], ans = 0;

    cin >> N >> M;
    ans += 2*N*M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> block[i][j];
        }
    }

    for(int i=0;i<N;i++){
        vector<pair<bool, int>> status; // 증가 / end
        bool is_first = true, is_second = true, increase;
        int tmp;
        for(int j=0;j<M;j++){
            if(is_first){
                tmp = block[i][j];
                is_first = false;
            } else if (is_second){
                if(tmp!=block[i][j]){
                    is_second = false;
                    increase = tmp<block[i][j];
                    tmp = block[i][j];
                }
            } else{
                if((increase && (tmp > block[i][j])) || (!increase && (tmp < block[i][j]))){
                    tmp = block[i][j];
                    status.emplace_back(increase, j-1);
                }
            }
        }
        status.emplace_back(increase, M-1);

        ans += (status[0].first?block[i][status[0].second]:block[i][0]);

        int locate = 0;
        while(locate<status.size()-1){

            locate++;
        }
    }

    return 0;
}
