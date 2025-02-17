#include <iostream>
using namespace std;
#define MOD 1000000007;
typedef long long ll;
ll qpow(ll a, ll n) {
    if(n==0) {
        return 1;
    } else if(n%2==1) {
        return qpow(a, n-1) * a;
    } else {
        ll temp = qpow(a, n/2);
        return temp * temp;
    }
}

int main() {
    cout << qpow(2, 20);
    return 0;
}