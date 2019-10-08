#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> message;
    int n, k;
    cin >> n >> k;
    while(n--){
        int target;
        cin >> target;
        if(find(message.begin(), message.end(), target)!=message.end()) continue;
        //if(is_there(message, target))
        //if(id[target-1]) continue;
        if(message.size()<k) message.push_front(target);
        else{
            //id[message.back()-1]=0;
            message.pop_back();
            message.push_front(target);
        }
        //id[target-1]=1;
    }
    cout << message.size() << '\n';
    while(!message.empty()){
        cout << message.front() << " ";
        message.pop_front();
    }
}