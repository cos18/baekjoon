#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, arr[50];
    cin >> n;
    if(n==1){
        cout << 'A' << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    if (n==2){
        if(arr[0]==arr[1]) cout << arr[0] << endl;
        else cout << 'A' << endl;
        return 0;
    }
    if(arr[0]==arr[1]){
        for(int i=2;i<n;i++){
            if(arr[i-1]!=arr[i]){
                cout << 'B' << endl;
                return 0;
            }
        }
        cout << arr[0] << endl;
    } else {
        a = (arr[2]-arr[1])/(arr[1]-arr[0]);
        b = arr[2]-arr[1]*a;
        for(int i=1;i<n;i++){
            if(arr[i]!=a*arr[i-1]+b){
                cout << 'B' << endl;
                return 0;
            }
        }
        cout << arr[n-1]*a+b << endl;
    }

}