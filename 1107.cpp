#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> button, channel;
int go(int locate, int target, int length){
    int ans;
    if(locate==length){
        ans = 0;
        for(int i=0;i<locate;i++){
            ans= ans*10 + channel[i];
        }
        //cout << ans << endl;
        return abs(target-ans)+locate;
    }
    ans = 10000000;
    for(int i=0;i<button.size();i++){
        if(locate==0 && button[i]==0) continue;
        channel.push_back(button[i]);
        int test = go(locate+1, target, length);
        ans = (ans>test)?test:ans;
        channel.pop_back();
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, check[10]={}, tmp;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> tmp;
        check[tmp]=1;
    }
    for(int i=0;i<10;i++){
        //cout << "check[i] : " << check[i] << endl;
        if(check[i]) continue;
        button.push_back(i);
    }
    //cout << "button : " << button.size() << "\n";
    int ans = abs(N-100), length=0;
    if(!check[0]) ans = (ans>(N+1))?(N+1):ans;
    tmp = N;
    do{
        tmp /= 10;
        length++;
    } while(tmp>0);
    for(int i=-1;i<2;i++){
        if(length+i>0){
            int test = go(0, N, length+i);
            ans = (ans>test)?test:ans;
        }
    }
    cout << ans << "\n";
}