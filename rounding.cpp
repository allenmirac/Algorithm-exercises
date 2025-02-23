#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 蓝桥杯题号：502. 成绩统计
// 将得到的百分数四舍五入。
int main()
{
    int n;
    cin >> n;
    float sum1=0, sum2=0;
    for(int i=0; i<n; i++) {
        int b;
        cin >> b;
        if(b>=60) sum1++;
        if(b>=85) sum2++;
    }
    int a1=sum1/n*100+0.5;
    int a2=sum2/n*100+0.5;
    cout << a1  << "%" << endl;
    cout << a2 << "%" <<  endl;
    // 请在此输入您的代码
    return 0;
}