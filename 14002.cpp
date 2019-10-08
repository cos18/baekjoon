#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, lis[1000][2]={}, arr[1000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int last_locate=0, last_cnt=1;
    for(int i=0;i<n;i++){
        lis[i][0]=1;
        lis[i][1]=-1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && lis[j][0]+1>lis[i][0]){
                lis[i][0] = lis[j][0]+1;
                lis[i][1] = j;
            }
        }
        if(lis[i][0]>last_cnt){
            last_locate=i;
            last_cnt = lis[i][0];
        }
    }
    cout << last_cnt << '\n';
    stack<int> print;
    while(last_locate!=-1){
        print.push(arr[last_locate]);
        last_locate = lis[last_locate][1];
    }
    while(!print.empty()){
        cout << print.top() << ' ';
        print.pop();
    }
    return 0;
}