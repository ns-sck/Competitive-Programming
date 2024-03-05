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
    int n, m; cin >> n >> m;
    vi v(n);
    vii dp(n+1, vi(m+1, 0));
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    if (v[0] == 0)
        for (int i = 1; i <= m; ++i)
            dp[0][i] = 1;
    else {
        dp[0][v[0]] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (v[i] == 0) {
            for (int j = 1; j <= m; ++j) {
        
                dp[i][j] += dp[i-1][j-1] % MOD;
                dp[i][j] += dp[i-1][j] % MOD;
                if (j+1 <= m)
                    dp[i][j] += dp[i-1][j+1] % MOD;
            }
        }
        else {
            dp[i][v[i]] += dp[i-1][v[i]-1] % MOD;
            dp[i][v[i]] += dp[i-1][v[i]] % MOD;
            if (v[i] < m) {
                dp[i][v[i]] += dp[i-1][v[i]+1] % MOD;
            }
        }
    }
    int ans = 0;
    for (auto x : dp[n-1]) {
        ans = (ans + x) % MOD;
    }
    cout << ans;
    return 0;
}
