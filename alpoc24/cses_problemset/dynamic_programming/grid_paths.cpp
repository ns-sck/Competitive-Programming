#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
int n;
vii dp(1e3+1, vi(1e3+1, -1));
int dfs(vector<vector<bool>>& b, int i, int j)
{   
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n-1 && j == n-1)
        return 1;
    int ans = 0;
    b[i][j] = false;

    if (i+1 < n && b[i+1][j])
        ans = (ans + dfs(b, i+1, j)) % MOD;
    if (j+1 < n && b[i][j+1])
        ans = (ans + dfs(b, i, j+1)) % MOD;

    b[i][j] = true;
    dp[i][j] = ans;
    return ans;
}

int32_t main() {

    cin >> n;
    vector<vector<bool>> b(n, vector<bool>(n, true));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            if (c == '*')
                b[i][j] = false;
        }
    }
    if (!b[0][0])
        dp[0][0] = 0;
    cout << dfs(b, 0, 0);
    return 0;
}
