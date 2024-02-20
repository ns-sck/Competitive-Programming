//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1e9 + 7;
int32_t main() {
// write your code here
    int n;
    cin >> n;
    
    vector<vector<int>> dp(n+1, vector<int>(10, 0));
    if (n == 1) {
        cout << 9;
        return 0;
    }
    
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i][1] += (dp[i-1][6] + dp[i-1][7] + dp[i-1][8] + dp[i-1][9]) % MOD;
        dp[i][2] += (dp[i-1][7] + dp[i-1][8] + dp[i-1][9]) % MOD;
        dp[i][3] += (dp[i-1][8] + dp[i-1][9]) % MOD;
        dp[i][4] += (dp[i-1][9]) % MOD;
        dp[i][6] += (dp[i-1][1]) % MOD;
        dp[i][7] += (dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][8] += (dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][9] += (dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4]) % MOD;
    }
    int ans = 0;
    for (auto x : dp[n]) {
        ans += x;
        ans %= MOD;
    }
    cout << ans;

	return 0;
}
