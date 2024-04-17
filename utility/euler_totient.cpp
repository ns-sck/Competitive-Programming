#include <bits/stdc++.h>
#define ii pair<int,int>

using ll = long long;
using namespace std;

const int mod = 1e9 + 7;

ll totient(ll n) {
    int m = 1e6 + 5;
    vector<bool> isPrime(m, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = 2*i; j <=n; j += i) { 
                isPrime[j] = false;
            }
        }
    }
    ll ans = n;
    bool flag = false;
    for(int &x : primes) {
        if(n % x == 0) {
            ans /= x;
            ans *= (x-1);
            while(n % x == 0){
                n /= x;
            }
        }
    }
    if(n != 1) {
        ans /= n;
        ans *= (n-1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;
    cout << totient(n);

    return 0;
}