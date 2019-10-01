#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> bag;
    int a, sum=0;
    for(int i=0;i<4;i++){
        cin >> a;
        bag.push_back(a);
        sum+=a;
    }
    for(int i=0;i<4;i++){
        int newbag = sum-bag[i];
        if(newbag==bag[i]){
            printf("YES");
            return 0;
        }
    }
    if(sum%2){
        printf("NO");
        return 0;
    }
    sum /= 2;
    sum -= bag[0];
    for(int i=1;i<4;i++){
        if(sum == bag[i]){
            printf("YES");
            return 0;
        }
    }

    printf("NO");
}