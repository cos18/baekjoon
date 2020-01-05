#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> gap, ja;
    string tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        gap.push_back(tmp);
    }
    for(int j=0;j<m;j++){
        cin >> tmp;
        ja.push_back(tmp);
    }
    int t;
    cin >> t;
    while(t--){
        int year;
        cin >> year;
        int g, j;
        g = year%n-1;
        if(g==-1) g = n-1;
        j = year%m-1;
        if(j==-1) j = m-1;
        cout << gap[g] << ja[j] << '\n';
    }

    return 0;
}
