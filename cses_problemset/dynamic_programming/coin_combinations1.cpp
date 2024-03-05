#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int32_t main() {

    ios;
    int n, x; cin >> n >> x;
    vi v(n);
    vi dp(x+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - v[j] >= 0) {
                dp[i] = (dp[i] + dp[i-v[j]]) % MOD;
            }
        }
    }
    cout << dp[x];
    
    return 0;
}
