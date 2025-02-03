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
    int n; cin >> n;
    vii dp(1e6+1, vi(8));

    for (auto& x : dp[1])
        x = 1;
    for (int i = 2; i <= 1000000; ++i) {
        dp[i][0] = (dp[i-1][7] + dp[i-1][0] + dp[i-1][3]) % MOD;
        dp[i][3] = (dp[i-1][0] + dp[i-1][3] + dp[i-1][7]) % MOD;
        dp[i][4] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6] + dp[i-1][7]) % MOD;
        dp[i][5] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6] + dp[i-1][7]) % MOD;
        dp[i][6] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6] + dp[i-1][7]) % MOD;
        dp[i][7] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6] + dp[i-1][7]) % MOD;
    }
    while (n--) {
        int a; cin >> a;
        cout << (dp[a][3] + dp[a][7]) % MOD << '\n';
    }
    return 0;
}
