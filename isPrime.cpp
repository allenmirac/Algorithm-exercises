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