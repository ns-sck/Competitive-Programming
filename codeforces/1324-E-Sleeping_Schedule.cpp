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
const ll MAX = 2e3+1;
const long double EPS = 1e-9; 

vvi dp(MAX, vi(MAX));
void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    int ans = 0;
    vi v(n);
    for (auto& x : v) cin >> x;
    for (int i = n-1; ~i; --i)
        for (int j = 0; j < h; ++j) {
            int x = (v[i]+j)%h, y = (x+h-1)%h;
            dp[i][j] = dp[i+1][x] + (x >= l && x <= r);
            dp[i][j] = max(dp[i][j], dp[i+1][y] + (y >= l && y <= r));
        }
    cout << dp[0][0];
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
