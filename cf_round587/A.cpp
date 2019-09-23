#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, cnt=0;
    char ab[200001];
    cin >> N;
    cin >> ab;
    for(int i=0;i<N/2;i++){
        if(ab[2*i]==ab[2*i+1]) {
            cnt++;
            ab[2*i] = ((ab[2*i]=='a')?'b':'a');
        }
    }
    cout << cnt << '\n' << ab;
}