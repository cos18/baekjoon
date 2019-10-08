#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b){
    if(a<b){
        a = a^b;
        b = a^b;
        a = a^b;
    }
    if(!b) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return a*b/gcd(a, b);
}

bool sortnew(long long a, long long b){
    return a>b;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        long long n, ticket[200000], x, y, a, b;
        long long k;
        cin >> n;
        for(long long i=0;i<n;i++){
            cin >> ticket[i];
        }
        sort(ticket, ticket+n, sortnew);
        cin >> x >> a >> y >> b >> k;
        long long l = lcm(a, b);
        if(x>y){
            a = a^b; b=a^b; a=a^b;
            x = x^y; y = x^y; x=x^y;
        }
        long long target=-1, locatea = 0, locateb = 0, locateab = 0;
        long long sum=0;
        for(long long i=1;i<=n;i++){
            if(i%l==0){
                sum += ticket[locatea++]/100LL*x;
                sum += ticket[locateb++]/100LL*(y-x);
                sum += ticket[locateab++]/100LL*x;
            }else if(i%b==0){
                sum += ticket[locatea++]/100LL*x;
                sum += ticket[locateb++]/100LL*(y-x);
            }else if(i%a==0){
                sum += ticket[locatea++]/100LL*x;
            }
            if(sum>=k){
                target=i;
                break;
            }
        }
        cout << target << '\n';
    }
}