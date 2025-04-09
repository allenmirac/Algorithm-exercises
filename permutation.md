# 全排列

第一种方法是递归的方法，第二种方法是Algorithm中的，但是注意`std::next_permutation`，是基于字典序的。

比如在这个示例中，`{5,6,7,4,3}`，前三个是升序的，只会生成基于这前三个的全排列（55个），而不会生成完整的全排列（120个）。

正确使用 next_permutation 的姿势是：必须先将输入排序为最小字典序，即：
```cpp
sort(nums.begin(), nums.end());
```

Leetcode46. 全排列。

```cpp
void backtrace(vector<vector<int>>& res, int start, vector<int>& nums) {
	if(start == nums.size()) {
		res.push_back(nums);
		return ;
	}
	for(int i=start; i<nums.size(); i++) {
		swap(nums[start], nums[i]);
		backtrace(res, start+1, nums);
		swap(nums[start], nums[i]);	
	}
}

void permutation(vector<vector<int>>& res, vector<int>& nums) {
	do{
		res.push_back(nums);
	}while(next_permutation(nums.begin(), nums.end()));
}

void solve() {
	vector<vector<int>> res;
	vector<int> nums = {5,6,7,4,3};
//	backtrace(res, 0, nums);
	permutation(res, nums); 
	int count=0;
	for(int i=0; i<res.size(); i++) {
		for(int j=0; j<res[i].size(); j++) {
			cout << res[i][j] << ",";
		}
		count++;
		cout << endl;
	}
	cout << "Count: " << count << endl;;
}
```