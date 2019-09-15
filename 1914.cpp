#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

vector<pair<int, int>> list;
vector<vector<int>> big_number;

// 100 : 1267/650600228/230000000/000000000

double go_double(int n){
    if(n==0) return 1;
    return go_double(n-1)*2;
}

void go_big(int n){
    vector<int> start{1};
    big_number.push_back(start);
    int cnt = 0;
    while(cnt!=n+1){
        vector<int> newnum;
        int local_cnt = big_number[cnt].size();
        for(int i=0;i<local_cnt;i++){
            int cal = big_number[cnt][i]*2;
            int over = cal/100000000;
            cal %= 100000000;
            if(newnum.size()<=i) newnum.push_back(cal);
            else newnum[i]+=cal;
            if(over){
                if(newnum.size()>i+1) newnum[i+1]+=over;
                else newnum.push_back(over);
            }
        }
        big_number.push_back(newnum);
        cnt++;
    }
    int locate = 0, check=1;
    while(true){
        if(big_number[n][locate]){
            big_number[n][locate]--;
            break;
        }
        locate++;
    }
    for(int i=big_number[n].size()-1;i>=0;i--){
        if(check){
            cout << big_number[n][i];
            check=0;
        } else cout << setw(6) << setfill('0') << big_number[n][i];
    }
    cout << "\n";
}

long long go(int from, int to, int size){
    // size개의 원반탑을 from에서 to로 이동한다.
    if(size==1){
        list.push_back(make_pair(from, to));
        return 1;
    }
    long long first, last;
    first = go(from, 6-from-to, size-1);
    list.push_back(make_pair(from, to));
    last = go(6-from-to, to, size-1);
    return first+1+last;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    if(N<=20){
        long long cnt = go(1, 3, N);
        cout << cnt << "\n";
        for(long long i=0;i<cnt;i++){
            cout << list[i].first << " " << list[i].second << "\n";
        }
    } else {
        string s = to_string(pow(2, N));
        s[s.size()-7]='\0';
        s[s.size()-8]-=1;
        int i=0;
        do{
            cout << s[i++];
        } while(s[i]!='\0');
    }

}