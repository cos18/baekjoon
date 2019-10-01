#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long cnt=1, wordcnt[2]={26, 10};
    string pattern;
    cin >> pattern;
    for(int i=0;i<pattern.size();i++){
        if(i){
            if(pattern[i-1]==pattern[i]) cnt*=(wordcnt[pattern[i]-'c']-1);
            else cnt*=(wordcnt[pattern[i]-'c']);
        } else cnt*=(wordcnt[pattern[i]-'c']);
        cnt %= 1000000009;
    }
    cout << cnt;
}