#include <iostream>
#include <queue>
#include <tuple>
#include <set>

#define MAX 1000000000
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long s, t;
    set<long long> check;
    cin >> s >> t;

    if(s==t){
        cout << 0;
        exit(0);
    }

    // '*', '+', '-', '/'
    queue<pair<long long, string>> q;
    q.emplace(s, "");
    check.insert(s);
    string ans;
    while(!q.empty()){
        tie(s, ans) = q.front();
        q.pop();
        if(s==t){
            cout << ans;
            exit(0);
        }

        if(s*s<=MAX && (check.find(s*s) == check.end())){
            check.insert(s*s);
            q.emplace(s*s, ans+"*");
        }

        if(s+s<=MAX && (check.find(s+s) == check.end())){
            check.insert(s+s);
            q.emplace(s+s, ans+"+");
        }

        if(check.find(1) == check.end()){
            check.insert(1);
            q.emplace(1, ans+"/");
        }
    }

    cout << -1;

    return 0;
}
