#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 15분? 10분?

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ya, yb, n, m, tmp;
    vector<int> xa, xb;
    cin >> n >> m >> ya >> yb;
    for(int i=0;i<n;i++){
        cin >> tmp;
        xa.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        cin >> tmp;
        xb.push_back(tmp);
    }
    sort(xa.begin(), xa.end());
    sort(xb.begin(), xb.end());
    int alocate=0, blocate=0, min = 100000000*4+1, dy = abs(ya-yb), cnt=0;
    while(alocate!=n && blocate!=m){
        int cal = abs(xa[alocate]-xb[blocate])+dy;
        if(cal==min) cnt++;
        if(cal<min){
            cnt = 1;
            min=cal;
        }
        if(xa[alocate]==xb[blocate]){
            if(n-alocate > m-blocate) alocate++;
            else blocate++;
        } else if (xa[alocate]>xb[blocate]) blocate++;
        else alocate++;
    }
    cout << min << " " << cnt;
}