#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

// TODO : 16%... 많이 발전

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int W, lo=0, l=0, b=0;
    char tmp[70002];
    string query;
    stack<char> gwalho;
    cin >> W;
    getchar();
    cin.getline(tmp,70001,'\n');
    for(int i=0;i<strlen(tmp);i++){
        if(tmp[i]!=' ') query+=tmp[i];
    }
    while(lo!=query.size()){
        switch(query[lo]){
            case ',':
                if(lo == 0
                   || lo == query.size() - 1
                   || (query[lo + 1] != 'S' && query[lo + 1] != 'L' && query[lo + 1] != 'B')
                   || (query[lo - 1] != 'S' && query[lo - 1] != ')' && query[lo - 1] != ']')){
                    cout << -1;
                    return 0;
                }
                break;
            case ')':
            case ']':
                if(gwalho.empty() || (gwalho.top()!=((query[lo] == ')') ? '(' : '['))){
                    cout << -1;
                    return 0;
                }
                gwalho.pop();
                break;
            case 'S':
                if(lo != query.size() - 1 && (query[lo + 1] != ',' && query[lo + 1] != ')' && query[lo + 1] != ']')){
                    cout << -1;
                    return 0;
                }
                break;
            case 'L':
            case 'B':
                if(query[lo] == 'L') l++;
                else b++;
                lo++;
                if(lo > query.size() - 3 || (query[lo] != '(' && query[lo] != '[') || (query[lo] == '(' && query[lo + 1] == ')') || (query[lo] == '[' && query[lo + 1] == ']')){
                    cout << -1;
                    return 0;
                }
                gwalho.push(query[lo]);
                break;
            default:
                cout << -1;
                return 0;
        }
        lo++;
    }
    if(!gwalho.empty()){
        cout << -1;
        return 0;
    }
    cout << ((query.size())?b+W*l+1:-1);
}