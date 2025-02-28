## 蓝桥杯题号：549. 扫雷
```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 105
int g[N][N], v[N][N];
int n, m;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
struct Node {
    int x, y;
};
void bfs() {
    queue<Node> que;
    que.push({1, 1});
    v[1][1]=1;
    while(!que.empty()) {
        Node temp = que.front();
        que.pop();
        int sum=0;
        int x = temp.x, y = temp.y;
        for(int i=0; i<8; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]==9) {
                sum++;
            }
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && v[nx][ny]==0) {
                que.push({nx, ny});
                v[nx][ny]=1;
                // cout << nx << "," << ny << "|";
            }
        }
        // cout << "=";
        if(g[x][y]!=9) g[x][y]=sum;
    }
}
int main()
{
    
    cin >> n >> m;
    for(int i=1; i<=n ;i++) {
        for(int j=1; j<=m; j++){
            cin >> g[i][j];
            if(g[i][j]==1) g[i][j]=9;
        }
    }
    bfs();
    // cout << endl;
    for(int i=1; i<=n ;i++) {
        for(int j=1; j<=m; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## 蓝桥杯题号：141. 穿越雷区

```cpp
#include <iostream>
#include <queue>
using namespace std;
// 
#define MAXN 101
int g[MAXN][MAXN], v[MAXN][MAXN];

struct steps {
    int sx, sy;
    int step, radar;
    steps() { // 为了初始化方便
        this->sx = 0, this->sy = 0;
        this->step = 0, this->radar = 0;
    }
    steps(int x, int y, int step, int radar) { // 带参数的初始化
        this->sx = x, this->sy = y;
        this->step = step, this->radar = radar;
    }
};
queue<steps> que;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(int sx, int sy, int ex, int ey) {
    steps start;
    v[sx][sy]=1;
    start.sx=sx, start.sy=sy, start.step=0, start.radar=0;
    que.push(start);
    while(!que.empty()) {
        steps temp = que.front();
        que.pop();
        int x = temp.sx, y = temp.sy;
        if(x==ex && y==ey) {
            return temp.step;
        }
        for(int i=0; i<4; i++) {
            x = temp.sx+dx[i], y = temp.sy+dy[i];
            if(v[x][y]==0 && g[temp.sx][temp.sy] != g[x][y]) { // 不同题目需要修改不同的判断条件
                v[x][y]=1;
                que.push(steps(x, y, temp.step+1, g[x][y]));
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    char c;
    int sx, sy, ex, ey;
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n+1; j++) {
            cin >> c;
            if(c=='A') {
                sx=i, sy=j;
                g[i][j]=0;
            } else if(c=='B') {
                ex=i, ey=j;
                g[i][j]=2;
            } else if(c=='+') {
                g[i][j]=1;
            } else if(c=='-') {
                g[i][j]=-1;
            }
        }
    }
    for(int i=0; i<n+1; i++) { // 初始化为不需要的值，意味着两堵墙
        g[0][i] = 3;
        g[i][0] = 3;
    }
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<n+1; j++) {
            v[i][j]=0;
        }
    }
    cout << bfs(sx, sy, ex, ey);
    return 0;
}
```