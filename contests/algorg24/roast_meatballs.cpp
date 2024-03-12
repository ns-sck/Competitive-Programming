#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 1e9+7;
const int _max = 2e5+1;
int brd[18][18];
vi dp((1 << 18)+1, - 1);
int n;
int allmask;

int dfs(int mask, int r) {
    if (mask == allmask)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (((1 << i) & mask) == 0) {
            ans = max(ans, dfs(mask | (1 << i), r+1)+ brd[r][i]);
        }
    }
    dp[mask] = ans;
    return ans;
}

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> brd[i][j];
        }
        
    allmask = (1 << n) - 1;
    cout << dfs(0, 0);
    return 0;
}
