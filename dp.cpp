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
// 蓝桥杯题号：17627. 云神的货币系统
bool is_mul = 0;
bool is_file = 0;
bool is_stdin = 1;

const int N = 100010, mod = 1000000007;

void solve() {
    int n, x;
    cin >> n >> x;
    vi coins(n, 0);
    rep(i, 0, n-1) {
        cin >> coins[i];
    }
    vi dp(x+1, x+1);
    dp[0] = 0; // 0元需要0个硬币
    for(int coin : coins) { // 从coin开始
        for(int i=coin; i<=x; i++) {
            dp[i] = min(dp[i], dp[i-coin]+1);//状态转移方程
        }
    }
    if(dp[x]==x+1) cout << -1 << endl;
    else cout << dp[x];
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