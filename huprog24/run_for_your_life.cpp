#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 1e9+7;
const int _max = 2e3+1;

vii grid(_max, vi(_max));
vii dp(_max, vi(_max, -1));
vii dp2(_max, vi(_max, -1));
vector<vector<pii>> t(11, vector<pii>());
int n, m;
bool b(int r, int c) {
    return r < n && c < m && grid[r][c] != -1;
}

bool b2(int r, int c) {
    return r >= 0 && c >= 0 && grid[r][c] != -1;
}

int dfs(int r, int c) {
    if (r == n-1 && c == m-1)
        return 1;
    if (dp[r][c] != -1)
        return dp[r][c];
    int ans = 0;
    if (b(r+1, c))
        ans = (ans + dfs(r+1, c)) % MOD;
    if (b(r, c+1))
        ans = (ans + dfs(r, c+1)) % MOD;
    dp[r][c] = ans % MOD;
    return ans % MOD;
}

int dfs2(int r, int c) {
    if (r == 0 && c == 0)
        return 1;
    if (dp2[r][c] != -1)
        return dp2[r][c];
    int ans = 0;
    if (b2(r-1, c))
        ans = (ans + dfs2(r-1, c)) % MOD;
    if (b2(r, c-1))
        ans = (ans + dfs2(r, c-1)) % MOD;
    dp2[r][c] = ans % MOD;
    return ans % MOD;
}

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            grid[i][j] = x;
            if (x > 0) {
                t[x].push_back({i,j});
            }
        }
    }
    int ans = 0;
    dfs2(n-1, m-1);
    ans = (ans + dfs(0, 0)) % MOD;
    for (int i = 1; i < 11; ++i) {
        if (t[i].size() == 2) {
            auto p1 = t[i][0];
            auto p2 = t[i][1];
            dfs(p1.first, p1.second);
            dfs2(p1.first, p1.second);
            dfs(p2.first, p2.second);
            dfs2(p2.first, p2.second);
            int w1 = dp[p1.first][p1.second];
            int w2 = dp[p2.first][p2.second];
            int w3 = dp2[p1.first][p1.second];
            int w4 = dp2[p2.first][p2.second];
            if (w3 > 0 && w2 > 0)
                ans  = (ans + ((w3 * w2) % MOD)) % MOD;
            if (w1 > 0 && w4 > 0)
                ans  = (ans + ((w1 * w4) % MOD)) % MOD;
        }
    }
    
    cout << ans;
    return 0;
}
