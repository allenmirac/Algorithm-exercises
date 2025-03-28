#include <iostream>
#include <vector>
using namespace std;

vector<int> reduce(const vector<int>& prime, int n) {
    int sz = prime.size();
    vector<int> rest;
    for(int i=0; i<sz; i++) {
        if(n==1) {
            break;
        }
        if(prime[i]*prime[i] > n) {
            rest.push_back(n);
            break;
        }
        while(n%prime[i] == 0) {
            n /= prime[i];
            rest.push_back(prime[i]);
        }
    }
    return rest;
}

int main() {
    vector<int> prime = {2, 3, 5, 7, 11, 13};
    vector<int> rest;
    int n = 125;
    rest = reduce(prime, n);
    cout << rest[0];
    for(int i=1; i<rest.size(); i++) {
        cout << "*" << rest[i];
    }
    cout << "=" << n;
    return 0;
}