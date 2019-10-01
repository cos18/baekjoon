#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, a[100], wait[100]={}, locate=0;
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<N;i++){
        int newlocate=0;
        while(newlocate<locate){
            if(wait[newlocate]<a[i]){
                wait[newlocate] = a[i];
                break;
            }
            newlocate++;
        }
        if(newlocate==locate) wait[locate++] = a[i];
    }
    cout << (locate<=K?"YES":"NO");
}