#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int jari, number[10], check[10];
char budungho[10];

vector<long long> final;

void go(int locate){
    if(locate==jari+1){
        long long ans = 0;
        for(int i=0;i<jari+1;i++){
            ans = ans*10+number[i];
        }
        final.push_back(ans);
        return;
    }
    for(int i=0;i<10;i++){
        if(check[i]) continue;
        if(locate){
            if((budungho[locate]=='<' && number[locate-1]>i)||(budungho[locate]=='>' && number[locate-1]<i)) continue;
        }
        number[locate]=i;
        check[i]=1;
        go(locate+1);
        check[i]=0;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> jari;
    for(int i=1;i<=jari;i++){
        cin >> budungho[i];
    }
    go(0);
    sort(final.begin(), final.end());
    cout << final[final.size()-1] << "\n" << setw(jari+1) << right << setfill('0') << final[0];
}