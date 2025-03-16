# 树形DP入门
## LeetCode337. 打家劫舍 III

在做这一类题的时候，还是感觉没有办法按照DP的思路一步步想，很乱

1. 考虑的第一点，使用什么方式遍历树（前中后序?），为什么最后选择后序遍历

2. 考虑的第二点，定义好`dp[i]`的含义，发现没有确定好第一步，第二步做不下去。

### 解法一

使用这种解法，肯定会超时，因为重复计算每个节点的值，这时候就想到一个优化的点，存储计算好的节点值。

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return root->val;
        // 选root
        int a = root->val;
        if(root->left) a += (rob(root->left->left) + rob(root->left->right));
        if(root->right) a += (rob(root->right->left) + rob(root->right->right));
        // 不选 root
        int b = rob(root->left) + rob(root->right);
        return max(a, b);
    }
};
```

### 解法二

在解法一的基础上，加入了记忆化搜索，也就是将计算好的值保存在`unordered_map`中。

```cpp
class Solution {
public: 
    unordered_map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return root->val;
        if(mp[root]) return mp[root];
        // 选root
        int a = root->val;
        if(root->left) a += (rob(root->left->left) + rob(root->left->right));
        if(root->right) a += (rob(root->right->left) + rob(root->right->right));
        // 不选 root
        int b = rob(root->left) + rob(root->right);
        mp[root] = max(a, b);
        return max(a, b);
    }
};
```

### 解法三

使用动态规划的思想，定义好`f`和`g`的含义，相当于有两个`dp`数组

```cpp
class Solution {
public: 
    unordered_map<TreeNode*, int> f, g; // f 选root, g 不选root
    void dfs(TreeNode* node) {
        if(node == nullptr) return ;
        if(node->left) dfs(node->left);
        if(node->right) dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        // for(auto item=f.begin(); item!=f.end(); item++) {
        //     cout << f[item->first] << ",";
        // }
        // cout << endl;
        // for(auto item=g.begin(); item!=g.end(); item++) {
        //     cout << g[item->first] << ",";
        // }
        return max(f[root], g[root]);
    }
};
```
