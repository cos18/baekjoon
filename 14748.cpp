#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

// TODO : 아직 WA(4%쯤에서)가 뜸.

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int W, location=0, l=0, b=0;
    char tmp[70000];
    string query;
    stack<char> gwalho;
    cin >> W;
    getchar();
    cin.getline(tmp,70000,'\n');
    for(int i=0;i<strlen(tmp);i++){
        if(tmp[i]!=' ') query+=tmp[i];
    }
    while(location!=query.size()){
        switch(query[location]){
            case ',':
                if(location==query.size()-1 || (query[location+1]!='S' && query[location+1]!='L' && query[location+1]!='B')){
                    cout << -1;
                    return 0;
                }
                break;
            case ')':
            case ']':
                if(gwalho.empty() || (gwalho.top()!=((query[location]==')')?'(':'['))){
                    cout << -1;
                    return 0;
                }
                gwalho.pop();
                break;
            case 'S':
                if(location!=query.size()-1 && (query[location+1]!=',' && query[location+1]!=')' && query[location+1]!=']')){
                    cout << -1;
                    return 0;
                }
                break;
            case 'L':
            case 'B':
                if(query[location]=='L') l++;
                else b++;
                location++;
                if(location>query.size()-3 || (query[location]!='(' && query[location]!='[') || query[location+1]==')' || query[location+1]==']'){
                    cout << -1;
                    return 0;
                }
                gwalho.push(query[location]);
                break;
            default:
                cout << -1;
                return 0;
        }
        location++;
    }
    if(!gwalho.empty()){
        cout << -1;
        return 0;
    }
    cout << b+W*l+1;
}