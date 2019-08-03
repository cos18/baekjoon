#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ascii[26];
    for(int i=0;i<26;i++){
        ascii[i] = -1;
    }
    string str;
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(ascii[str[i]-97]==-1){
            ascii[str[i]-97] = i;
        }
    }
    for(auto i : ascii){
        cout << i << " ";
    }
}