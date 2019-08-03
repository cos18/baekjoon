#include <iostream>
#include <vector>
using namespace std;

vector<int> nums={};
int k;

void go(int locate, int pick, int* save){
    if(pick==6){
        int out = 0;
        for(int i=0;i<k;i++){
            if(save[i]){
                out++;
                cout << nums[i] << ((out==6)?"\n":" ");
            }
        }
        return;
    }
    if(locate==k) return;
    save[locate] = 1;
    go(locate+1, pick+1, save);
    save[locate] = 0;
    go(locate+1, pick, save);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        int n, check[13]={};
        cin >> k;
        if(!k) break;
        if(nums.size()) cout << "\n";
        nums = {};
        for(int i=0;i<k;i++){
            cin >> n;
            nums.push_back(n);
        }
        go(0, 0, check);
    }

}
