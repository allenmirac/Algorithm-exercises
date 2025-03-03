#include <iostream>
using namespace std;
#define MOD 1000000007;
typedef long long ll;
ll qpow1(ll a, ll n) {
    if(n==0) {
        return 1;
    } else if(n%2==1) {
        return qpow1(a, n-1) * a;
    } else {
        ll temp = qpow1(a, n/2);
        return temp * temp;
    }
}

ll qpow2(int n, int i) {
    if(i==0) return 1;
    if(i==1) return n;
    if(i%2==1) {
        return n*qpow2(n*n, i/2)%MOD;
    } else {
        return qpow2(n*n, i/2)%MOD;
    }
}

int main() {
    cout << qpow2(2, 20);
    return 0;
}