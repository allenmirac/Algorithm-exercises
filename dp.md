# 蓝桥杯题号：17627. 云神的货币系统

```cpp
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
```
# 01背包问题
蓝桥杯题号：303. 求解 01 背包问题

为什么称为01背包，因为对于每一个item来说，它只可能有2种状态，要么选它要么不选它。

dp[i][j]: 表示在背包容量为j，可以选择前i个物品时，可以选择的最大价值量

```cpp
if(j<weight[i]) dp[i][j] = dp[i-1][j];
else {
    dp[i][j] = max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j]);//状态转移方程
}
```
状态转移
1. 如果 `j<weight[i]` ，说明剩余容量不足以选择当前第i个物品，最大价值依旧为前`i-1`个物品的最大价值，即`dp[i-1][j]`；
2. 如果`j>=weight[i]`，说明可以选择第`i`个物品，剩余的容量就剩下`j-weight[i]`，在剩余的容量里取前第`i-1`项的最大价值加上第i项的价值，即可表示选择了第i项的最大价值，即`value[i]+dp[i-1][j-weight[i]]`，然后比较选择第`i`个物品和不选择第`i`个物品的较大值，即为`max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j])`。

```cpp
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

const int N = 10010, mod = 1e9+7;
ll dp[1001][1001];
void solve() {
    int total, n;
    cin >> total >> n;
    vi value(n+1, 0), weight(n+1, 0);
    rep(i, 1, n) {
        cin >> weight[i] >> value[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=total; j++) {
            if(j<weight[i]) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j]);//状态转移方程
            }
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=total; j++) {
    //         cout << dp[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][total] << endl;
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
```
# 完全背包问题

蓝桥杯题号：304. 求解完全背包问题

与 01 背包的区别，就是物品可以重复选择。

与上面代码的区别，仅在于`dp[i][j] = max(value[i]+dp[i][j-weight[i]], dp[i-1][j]);`，max函数中的前者为`value[i]+dp[i][j-weight[i]]`，表示在选择第`i`个物品时，在剩余的容量里取前第`i`项的最大价值加上第`i`项的价值，即可表示选择了第`i`项的最大价值。

```cpp
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

const int N = 10010, mod = 1e9+7;
ll dp[1001][1001];
void solve() {
    int total, n;
    cin >> total >> n;
    vi value(n+1, 0), weight(n+1, 0);
    rep(i, 1, n) {
        cin >> weight[i] >> value[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=total; j++) {
            if(j<weight[i]) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(value[i]+dp[i][j-weight[i]], dp[i-1][j]);
            }
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=total; j++) {
    //         cout << dp[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][total] << endl;;
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
```