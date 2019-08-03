#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    string ps;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        stack<int> parenthesis;
        cin >> ps;
        for (int i = 0; i < ps.size(); i++) {
            if(ps.at(i)==')') {
                if(!parenthesis.size()){
                    cout << "NO\n";
                    break;
                }
                parenthesis.pop();
            } else parenthesis.push('(');
            if(i==ps.size()-1) cout << ((parenthesis.size())?"NO":"YES") << "\n";
        }
    }
    return 0;
}