#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long u64;
#define int ll
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<vector<int>>
#define SZ(x) (x).size()
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;

bool is_mul = 0;
bool is_file = 0;
bool is_stdin = 1;

const int N = 100010, mod = 1e9+7;
void solve() {

}
signed main() {
    if (is_stdin) {ios::sync_with_stdio(0);cin.tie(0);}
    if (is_file) {freopen("xxx.in","r",stdin);freopen("xxx.out","w",stdout);}

    if(is_mul) {
        int t;
        cin >> t;
        while (t--)
            solve();
    } else 
        solve();

    return 0;
}