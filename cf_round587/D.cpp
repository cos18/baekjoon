#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(a<b){
        a = a^b;
        b = a^b;
        a = a^b;
    }
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, tmp;
    vector<int> a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    int biggest = a[a.size()-1];
    for(int i=0;i<n-1;i++){
        a[i] = biggest - a[i];
    }
    int last = a[0];
    for(int i=0;i<n-1;i++){
        last = gcd(last, a[i]);
    }
    long long sum = 0;
    for(int i=0;i<n-1;i++){
        sum += a[i]/last;
    }
    cout << sum << " " << last;
}