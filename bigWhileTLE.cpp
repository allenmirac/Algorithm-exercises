#include <iostream>
#include <vector>
using namespace std;
int main() // O(1)
{
    long long a, b, n;
    int day=0;
    cin >> a >> b >> n;
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    long long sum=0, ans=0;
    int term = 5*a+2*b;
    long long weeks = n/term;
    n = n % term;
    ans += weeks*7;
    while(sum<n) {
        switch(vec[day]){
            case 1:
			case 2:
			case 3:
			case 4:
			case 5: {sum+=a; break;}
            case 6:
			case 7: {sum+=b; break;}
        }
		day = (day+1)%7;
        ans++;
    }
    cout << ans;
	// 请在此输入您的代码
	return 0;
}
// 解法一：会超时，原因：如果a=b=1，会导致while循环次数过多
// 一般的计算机每秒可执行约 10^8∼10^9 次运算，而 10^18 级别的循环需要的时间是不可接受的。
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() // O(n)
// {
//     int a, b, n;
//     int day=0;
//     cin >> a >> b >> n;
// 	vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
//     long long sum=0, ans=0;
//     while(sum<n) { 
//         switch(vec[day]){
//             case 1:
// 			case 2:
// 			case 3:
// 			case 4:
// 			case 5: {sum+=a; break;}
//             case 6:
// 			case 7: {sum+=b; break;}
//         }
// 		day = (day+1)%7;
//         ans++;
//     }
//     cout << ans;
// 	// 请在此输入您的代码
// 	return 0;
// }