#include <iostream>
#include <vector>

using namespace std;

int N;

vector<bool> is_cycle(3001);

bool check_cycle(int locate, vector<bool> cycle){

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> path[3001];
    cin >> N;
    for(int i=0;i<N;i++){
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    int check = 1;
    while(check<=N){
        vector<bool> tmp_cycle(3001);
        if(check_cycle(check, tmp_cycle)){
            is_cycle = tmp_cycle;
            break;
        }
        check++;
    }
}