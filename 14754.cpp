#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int map[1000][1000]={}, pizza[1000][1000], N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int jmax = 0, jlocation=0;
        for(int j=0;j<M;j++){
            cin >> pizza[i][j];
            if(jmax<pizza[i][j]){
                jmax = pizza[i][j];
                jlocation = j;
            }
        }
        map[i][jlocation] = 1;
    }
    for(int j=0;j<M;j++){
        int imax = 0, ilocation=0;
        for(int i=0;i<N;i++){
            if(imax<pizza[i][j]){
                imax = pizza[i][j];
                ilocation = i;
            }
        }
        map[ilocation][j] = 1;
    }
    unsigned long long ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!map[i][j]) ans += pizza[i][j];
        }
    }
    cout << ans;
}