#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 缺少这句话只能通过一半的样例
// 
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