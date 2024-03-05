#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int fastPow(int base, int exp) {
    int ans = 1;
    for(int i = 0; i < 45; i++) {
        if((1LL << i) & exp)
            ans *= base;

        base *= base;
        base %= MOD;
        ans %= MOD;
    }
    return ans;
}

int32_t main() {

    ios;
    int n; cin >> n;
    cout << fastPow(2, n);
    return 0;
}
