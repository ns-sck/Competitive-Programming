#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;
const ld EPS = 1e-9; 

void solve() {
    int N, K;
    cin >> N >> K;
    vvi dp(N+1, vi(5));
    dp[1][0] = 0, dp[1][1] = 0, dp[1][2] = 1, dp[1][3] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = (dp[i][0] + (i-K > 0 ? dp[i-K][2] : 0)) % MOD;
        dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
        dp[i][2] = (dp[i][2] + dp[i-1][1] + dp[i-1][3]) % MOD;
        dp[i][3] = (dp[i][3] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] - dp[i][0] + MOD) % MOD;
        dp[i][4] = (dp[i][4] + dp[i-1][2] + dp[i-1][4] - dp[i][0] + MOD) % MOD;
    }
    cout << (dp[N][0] + dp[N][1] + dp[N][2] + dp[N][3] + dp[N][4]) % MOD;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
