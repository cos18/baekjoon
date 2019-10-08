#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> arr(100000);

void init(vector<int> &seg, vector<int> &num, int node, int from, int to){
    if(from==to) seg[node] = num[from];
    else {
        init(seg, num, node*2, from, (from+to)/2);
        init(seg, num, node*2+1, (from+to)/2+1, to);
        seg[node] = min(seg[node*2], seg[node*2+1]);
    }
}

int query(vector<int> &seg, int node, int from, int to, int i, int j){
    if(i>to || j<from) return -1;
    if(i<=from && to<=j) return seg[node];
    int x = query(seg, node*2, from, (from+to)/2, i, j);
    int y = query(seg, node*2+1, (from+to)/2+1, to, i, j);
    if(x==-1) return y;
    if(y==-1) return x;
    return min(x, y);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, a, b;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int h = (int)ceil(log2(N));
    int segsize  =(1<<(h+1));
    vector<int> seg(segsize);
    init(seg, arr, 1, 0, N-1);
    while(M--){
        cin >> a >> b;
        cout << query(seg, 1, 0, N-1, a-1, b-1) << '\n';
    }
}