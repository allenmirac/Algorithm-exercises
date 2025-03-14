# 换硬币的题型
LeetCode518. 零钱兑换 II

`uint64_t`:刚开始做的时候一直超出`int`的范围，甚至超过了`long long`的范围，最后看题解（代码随想录）才知道是用这个（又有了问题，为什么LeetCode题解用int也可以过）

关键代码：
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount+1, 0));
        for(int i=0; i<n; i++) dp[i][0]=1;
        for(int j=0; j<=amount; j++) {
            if(j>=coins[0]) dp[0][j] = dp[0][j-coins[0]];
        }
        for(int i=1; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                dp[i][j] = dp[i-1][j];
                if(j>=coins[i]) dp[i][j] += dp[i][j-coins[i]];
            }
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<=amount; j++) {
        //         cout << dp[i][j] << ",";
        //     }
        //     cout << endl;
        // }
        return dp[n-1][amount];
    }
};
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

关键代码：
```cpp
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
```
# 完全背包问题

蓝桥杯题号：304. 求解完全背包问题

与 01 背包的区别，就是物品可以重复选择。

与上面代码的区别，仅在于`dp[i][j] = max(value[i]+dp[i][j-weight[i]], dp[i-1][j]);`，max函数中的前者为`value[i]+dp[i][j-weight[i]]`，表示在选择第`i`个物品时，在剩余的容量里取前第`i`项的最大价值加上第`i`项的价值，即可表示选择了第`i`项的最大价值。

关键代码:
```cpp
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
```

# 三维DP数组
LeetCode474. 一和零

`dp[i][j][k]`的含义：在下标为[0, i]范围内的字符串，满足0的数量<=j，并且1的数量<=k的最大字符串长度。

关键代码：
```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strSize = strs.size();
        vector<vector<int>> numsZeOne(strSize, vector<int>(2, 0));
        vector<vector<vector<int>>> dp(strSize+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i=0; i<strSize; i++) {
            string s = strs[i];
            int size = s.size();
            for(int j=0; j<size; j++){
                if(s[j] == '0') {
                    numsZeOne[i][0]++;
                } else numsZeOne[i][1]++;
            }
            // cout << "0:" << numsZeOne[i][0] << ",1:" << numsZeOne[i][1] << endl;
            for(int j=0; j<=m; j++) {
                for(int k=0; k<=n; k++) {
                    dp[i+1][j][k] = dp[i][j][k];
                    if(j>=numsZeOne[i][0] && k>=numsZeOne[i][1]) {
                        dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-numsZeOne[i][0]][k-numsZeOne[i][1]]+1);
                    }
                }
            }
        }        
        return dp[strSize][m][n];
    }
};
```