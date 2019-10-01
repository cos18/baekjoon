#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000001;
const int MOD = 1000000007;
int sosu[MAX+1]={1, 1, };
vector<int> sosus, primes;
vector<long long> primecnt;

long long modpow(int n, long long k){
    if(k==0) return 1;
    if(k==1) return n;
    if(k%2) return (modpow(n, k/2) * modpow(n, k/2)) % MOD;
    return (((modpow(n, k/2) * modpow(n, k/2))%MOD) * (n% MOD)) % MOD;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    long long n;
    for(int i=2;i*i<MAX;i++){
        if (sosu[i]) continue;
        sosus.push_back(i);
        for(int j=i*i;j<=MAX;j+=i) sosu[j]=1;
    }
    cin >> x >> n;
    for(int i : sosus){
        if(i*i>x) break;
        if(x%i==0){
            primes.push_back(i);
        }
    }
    int finalsize = primes.size();
    primecnt.assign(finalsize, 0);
    for(int i=0;i<primes.size();i++){
        long long test = primes[i];
        while (true){
            primecnt[i]+=(n/test);
            test *= test;
            if(n<test) break;
        }
    }
    long long finals=1;
    for(int i=0;i<finalsize;i++) {
        finals = (finals * modpow(primes[i], primecnt[i]))%MOD;
    }
    cout << finals;
}