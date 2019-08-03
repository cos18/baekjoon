#include <iostream>
#include <stack>
using namespace std;

stack<char> rstring, lstring;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string in;
    int n;
    char ch;
    cin >> in;
    for(auto c : in){
        lstring.push(c);
    }
    cin >> n;
    while(n--){
        cin >> ch;
        switch (ch){
            case 'D':
                if(!rstring.empty()){
                    lstring.push(rstring.top());
                    rstring.pop();
                }
                break;
            case 'L':
                if(!lstring.empty()){
                    rstring.push(lstring.top());
                    lstring.pop();
                }
                break;
            case 'B':
                if(!lstring.empty()){
                    lstring.pop();
                }
                break;
            default: // P
                cin >> ch;
                lstring.push(ch);
                break;
        }
    }
    char *result = new char[lstring.size()+rstring.size()+1];
    int locate = lstring.size(), i = locate;

    while(!lstring.empty()){
        result[--i] = lstring.top();
        lstring.pop();
    }
    while(!rstring.empty()){
        result[locate++] = rstring.top();
        rstring.pop();
    }
    result[locate] = '\0';
    cout << result << '\n';
}