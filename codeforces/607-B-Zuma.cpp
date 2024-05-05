#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
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
const ll MAX = 5e2+1;
const long double EPS = 1e-9; 

vvi dp(MAX, vi(MAX, 1e9));
// abcbaxyx|xyxbcba -> 2
// xyzx -> 2
// xyz|aba|zyx
// ACCCCCCCCCCCCCCCCCCCCCCCCCCCC ^_^
void solve() {
    int n; cin >> n;
    vi v(n);
    for (auto& x : v) cin >> x;
    for (int j = 0; j < n; ++j)
        for (int i = j; ~i; --i) {
            if (j == i) dp[i][j] = 1;
            if (j-i == 1) dp[i][j] = 1 + (v[i] != v[j]);
            if (j-i > 1) dp[i][j] = min(dp[i][j], dp[i+1][j-1] + (v[i] != v[j] ? 2 : 0));
            for (int k = i; k <= j && j-i; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
    cout << dp[0][n-1];
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
