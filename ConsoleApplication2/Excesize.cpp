//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <cstdio>
//#include <algorithm>
//#include <stack>
//using namespace std;
//void Print(int val)
//{
//    cout << val << " ";
//}
//bool IsSwap(vector<int> v, int nBegin, int nEnd)
//{
//    for (int i = nBegin; i < nEnd; i++)
//        if (v[i] == v[nEnd])
//            return false;
//    return true;
//}
//void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
//    if (first == len) {
//        res.push_back(output);
//        return;
//    }
//    for (int i = first; i < len; ++i) {
//        if (IsSwap(output, first, i))
//        {
//            swap(output.at(i), output.at(first));
//            backtrack(res, output, first + 1, len);
//            swap(output[i], output[first]);
//        }
//    }
//}
//vector<vector<int>> permute(vector<int>& nums) {
//    vector<vector<int> > res;
//    backtrack(res, nums, 0, nums.size());
//    for (int i = 0; i < res.size(); i++)
//    {
//        for (int j = 0; j < res.at(i).size(); j++)
//        {
//            cout << res.at(i).at(j)<< " ";
//        }
//        cout << endl;
//    }
//    return res;
//}
//
//int main()
//{
//
//    vector<int> output = { 1, 1, 1 };
//    permute(output);
//    return 0;
//}