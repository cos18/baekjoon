#include <iostream>
#include <vector>
using namespace std;

vector<int> nums, save;
int N, S;

int go(int locate){
    if(locate==N){
        if(save.size()==0) return 0;
        int sum = 0;
        for(int i : save){
            sum += i;
        }
        return (sum==S)?1:0;
    }
    int result = 0;
    save.push_back(nums[locate]);
    result += go(locate+1);
    save.pop_back();
    result += go(locate+1);
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> k;
        nums.push_back(k);
    }
    cout << go(0);

}
