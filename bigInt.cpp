#include<bits/stdc++.h>
using namespace std;
#define maxL 100
struct BigINT
{
    int len, a[maxL];
    BigINT(int x=0){
        memset(a, 0, sizeof(a));
        int i=0;
        if (x==0) len=1;
        else {
            for(; x!=0;){
                a[i] = x%10;
                i++;
                x /= 10;
            }
            len = i;
        }
    }
    int &operator[](int i){
        return a[i];
    }

    void flat(int l){
        len = l;
        for(int i=0; i<len; i++){
            a[i+1] += (a[i]/10);
            a[i] %= 10;
        }
        while(len>1 && a[len-1]==0) len--;
    }

    BigINT operator+(BigINT another){
        len = max(another.len, len)+1;
        for(int i=0; i<len; i++){
            a[i+1] += ((a[i]+another[i])/10);
            a[i] = ((a[i]+another[i])%10);
        }
        while(len > 1 && a[len-1] == 0) len --;
        return *this;
    }

    BigINT operator*(int j){
        len = len+10;
        for(int i=0; i<len; i++){
            a[i] = a[i] * j;
        }
        flat(len+10);
        while(len > 1 && a[len-1]==0){
            len --;
        }
        return *this;
    }
    void Print(){
        for(int i=len-1; i>=0; i--){
            cout << a[i];
        }
    }
};

int main(){
    BigINT res(1), sum;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        res = res * i;
        sum = sum + res;
    }
    sum.Print();
    return 0;
}