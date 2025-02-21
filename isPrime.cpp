#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n <= 3) return n > 1;
    int sqrtN =  sqrt(n*1.0);
    for(int i=2; i <= sqrtN; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
// 埃氏筛
int countPrime(int n) {
    int ans = 0;
    vector<int> isPrime(n, 1);
    // for(int i=2; i<n; i++) {
    //     if(isPrime[i]) ans++;
    //     for(long long j=i*i; j<n; j+=i) { // 这里i*i的计算还是int，计算完i*i之后才会转化为long long
    //         isPrime[i]=0;
    //     }
    // }
    for(int i = 2; i < n; i++) {
        if(isPrime[i]) ans++;
        if((long long)i * i >= n) continue;
        for(long long j = (long long)i * i; j < n; j += i) {
            isPrime[j] = 0;
        }
    }
    return ans;
}
int main(){
    return 0;
}