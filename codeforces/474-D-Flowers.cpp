#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 1e5+1;
const long double EPS = 1e-9; 

void solve() {

    int t, k;
    cin >> t >> k;
    vi dp(MAX+1), prfx(MAX+1); dp[0] = 1;
    for (int i = 0; i < MAX; ++i) {
        dp[i+1] = (dp[i] + dp[i+1]) % MOD;
        if (i+k <= MAX)
            dp[i+k] = (dp[i] + dp[i+k]) % MOD;
        if (i) prfx[i] = (prfx[i-1] + dp[i]) % MOD;
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << ((prfx[b] + MOD - prfx[a-1]) % MOD) << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
