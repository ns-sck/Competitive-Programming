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
const ll MAX = 1e6+1;
const long double EPS = 1e-9; 

void solve() {

    int n, k; 
    cin >> n >> k;
    string s; cin >> s;
    vvi v(k, vi());
    vi o(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int x = i%k;
        if (s[i] - '0') ++o[x];
        v[x].pb(s[i]-'0');
    }
    int ans = 1e9;
    for (int i = 1; i < k; ++i) o[i] += o[i-1];
    for (int i = 0; i < k; ++i) {
        int c = v[i][0], sz = v[i].size();
        vvi dp(2, vi(sz, 1e9));
        dp[0][0] = v[i][0];
        dp[1][0] = 1 - dp[0][0];
        for (int j = 1; j < sz; ++j) {
            dp[0][j] = min(dp[0][j-1], dp[1][j-1]) + v[i][j];
            dp[1][j] = min(c, dp[1][j-1]) + 1-v[i][j]; 
            c += v[i][j];
        }
        int x = min(dp[0][sz-1], dp[1][sz-1]) + o[k-1] - (o[i]);
        if (i) x += o[i-1];
        ans = min(ans, x);
    }
    cout << ans << '\n';
}
signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
