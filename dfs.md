## 题目一：3505. 买瓜
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 缺少这句话只能通过一半的样例
// 蓝桥杯题号：3505. 买瓜
#define int long long
int ans = 31;
vector<int> malon(31, 0), sum(31, 0);
int n, m;
bool cmp(int a, int b) {
    return a > b;
}

// 将这个算法想象成一棵三叉树
void dfs(int s, int i, int cnt) {
    if(cnt>=ans) return ;
    if(s==m) {ans = min(ans, cnt);}//找到了答案继续往下搜索，不返回，得到最小的值
    if(i>=n || s>=m || s+sum[i] < m) return ;
    dfs(s+malon[i], i+1, cnt);//1
    dfs(s+malon[i]/2, i+1, cnt+1);//0.5
    dfs(s, i+1, cnt);//0
}
signed main() { // 使用signed的原因是int被定义为long long了，不让编译会报错
    cin >> n >> m;
    m <<= 1;
    for(int i=0; i<n; i++) {
        cin >> malon[i];
        malon[i]<<=1;
    }
    sort(malon.begin(), malon.end(), cmp);
    for(int i=n-1; i>=0; i--) {
        sum[i] = sum[i+1] + malon[i];
    }
    dfs(0, 0, 0);
    if(ans==31) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
```
## 题目二：4234. 小怂爱水洼
```cpp
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// 蓝桥杯题号：4234. 小怂爱水洼
// 本体主要考察连通域的问题：
// 1. 从一个起点出发，计算相邻连通区域的和
// 2. 将整个图都遍历一遍，计算出这多个起点的连通域的值的最大值
#define MAXN 101
int g[MAXN][MAXN], v[MAXN][MAXN];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
long long ans=0; // 没事的时候可以开long long
int n, m;
long long tmp;

void dfs(int x, int y) {
    if(x<1 || y<1 || x>n || y>m) return ;
    if(v[x][y]==1 || g[x][y]==0) return ;
    v[x][y] = 1;
    tmp += g[x][y];
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}
int main()
{    
    cin >> n >> m;
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            cin >> g[i][j];
        }
    }
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(v[i][j]==1 || g[i][j]==0) continue;
            tmp=0;
            dfs(i, j);
            ans = max(tmp, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
```
## 题目三：Leetcode200. 岛屿数量

1. DFS写法

DFS函数在开始写的时候就需要考虑终止递归的条件！！

```cpp
class Solution {
public:
    void dfs(vector<vector<char>>& vG, int si, int sj) {
        int m = vG.size(), n = vG[0].size();
        vG[si][sj]='0';
        if(si>=0 && si<m && sj>=0 && sj<n) {
	        if (si - 1 >= 0 && vG[si - 1][sj] == '1')
	            dfs(vG, si - 1, sj);
	        if (sj - 1 >= 0 && vG[si][sj - 1] == '1')
	            dfs(vG, si, sj - 1);
	        if (si + 1 < m && vG[si + 1][sj] == '1')
	            dfs(vG, si + 1, sj);
	        if (sj + 1 < n && vG[si][sj + 1] == '1')
	            dfs(vG, si, sj + 1);
	    }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
```
2. BFS写法

```cpp
class Solution {
public:
    struct node {
        int x, y;
    };
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        int ans = 0;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        // queue<node> que;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                queue<node> que;
                if(grid[i][j]=='1') {
                    que.push({i, j});
                    while(!que.empty()) {
                        node f = que.front(); que.pop();
                        for(int i=0; i<4; i++) {
                            int nx = f.x+dx[i], ny = f.y+dy[i];
                            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1') {
                                que.push({nx, ny});
                                grid[nx][ny]='0';
                            }
                        }
                    }
                    ans++;
                }
            }
        }        
        return ans;
    }
};
```