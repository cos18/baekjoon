#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int path[101], check[101]={};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1;i<101;i++){
        path[i] = i;
    }

    int n, m;
    cin >> n >> m;
    for(int i=0;i<n+m;i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        path[tmp1] = tmp2;
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int locate = q.front();
        q.pop();
        if(locate==100) break;
        for(int i=1;i<=6;i++){
            if(locate+i>100) break;
            int next = path[locate+i];
            if(check[locate+i] || check[next]) continue;

            check[locate+i] = check[locate]+1;
            if(locate+i != next) check[next] = check[locate]+1;
            q.push(next);
        }
    }
    cout << check[100];

    return 0;
}
