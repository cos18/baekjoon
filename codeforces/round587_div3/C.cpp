#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    if((x1>=x3 && y1>=y3 && x2<=x4 && y2<=y4) || (x1>=x5 && y1>=y5 && x2<=x6 && y2<=y6)){
        cout << "NO";
        return 0;
    }
    if((max(x3, x5)<=x1 && min(x6, x4) >= x2 && y3<=y1 && y2<= y6 && y5 <= y4 && y1 <= y5 && y4 <= y2)){
        cout << "NO";
        return 0;
    }
    if((max(x3, x5)<=x1 && min(x6, x4) >= x2 && y5<=y1 && y2<= y4 && y3 <= y6 && y1 <= y3 && y6 <= y2)){
        cout << "NO";
        return 0;
    }
    if((max(y3, y5)<=y1 && min(y6, y4) >= y2 && x3<=x1 && x2<= x6 && x5 <= x4 && x1 <= x5 && x4 <= x2)){
        cout << "NO";
        return 0;
    }
    if((max(y3, y5)<=y1 && min(y6, y4) >= y2 && x5<=x1 && x2<= x4 && x3 <= x6 && x1 <= x3 && x6 <= x2)){
        cout << "NO";
        return 0;
    }
    if((x5<=x1 && y5<=y1 && x3<=x6 && y3<=y6 && x2<=x4 && y2<=y4) || (x3<=x1 && y3<=y1 && x5<=x4 && y5<=y4 && x2<=x6 && y2<=y6)){
        cout << "NO";
        return 0;
    }
    if((x3<=x1 && x1<=x4 && x4==x5 && x5<=x2 && x2<=x6 && max(y3, y5)<=y1 && min(y4, y6)<=y2) || (x5<=x1 && x1<=x6 && x6==x3 && x3<=x2 && x2<=x4 && max(y3, y5)<=y1 && min(y4, y6)<=y2)){
        cout << "NO";
        return 0;
    }
    if((y3<=y1 && y1<=y4 && y4==y5 && y5<=y2 && y2<=y6 && max(x3, x5)<=x1 && min(x4, x6)<=x2) || (y5<=y1 && y1<=y6 && y6==y3 && y3<=y2 && y2<=y4 && max(x3, x5)<=x1 && min(x4, x6)<=x2)){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}