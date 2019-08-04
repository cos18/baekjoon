#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, Y=0, M=0, time;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> time;
        Y += (time/30 + 1)*10;
        M += (time/60 + 1)*15;
    }
    if(Y<M){
        printf("Y %d", Y);
    } else if (Y>M){
        printf("M %d", M);
    } else {
        printf("Y M %d", Y);
    }
}