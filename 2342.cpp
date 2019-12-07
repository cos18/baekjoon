#include <iostream>

#define MAX 400001

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int map[100000];
    int dp[100000][5][5]={};
    int locate = 0;
    while(true){
        cin >> map[locate];
        if(map[locate]==0) break;
        locate++;
    }
    dp[0][map[0]][0] = 2;
    dp[0][0][map[0]] = 2;
    for(int now=1;now<locate;now++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(dp[now-1][i][j]){
                    if(map[now]!=j){
                        int i_dp = dp[now-1][i][j] + ((i==0)?2:(((map[now]-i)%2)?3:((map[now]==i)?1:4)));
                        if(dp[now][map[now]][j]){
                            dp[now][map[now]][j] = (dp[now][map[now]][j]>i_dp)?i_dp:dp[now][map[now]][j];
                        } else dp[now][map[now]][j] = i_dp;
                    }

                    if(map[now]!=i){
                        int j_dp = dp[now-1][i][j] + ((j==0)?2:(((map[now]-j)%2)?3:((map[now]==j)?1:4)));
                        if(dp[now][i][map[now]]){
                            dp[now][i][map[now]] = (dp[now][i][map[now]]>j_dp)?j_dp:dp[now][i][map[now]];
                        } else dp[now][i][map[now]] = j_dp;
                    }

                }
            }
        }
    }
    int ans = MAX;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(dp[locate-1][i][j]!=0){
                ans = (ans>dp[locate-1][i][j])?dp[locate-1][i][j]:ans;
            }
        }
    }
    cout << ans;
}