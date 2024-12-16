#include <bits/stdc++.h>
using namespace std;

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
const ll MAX = 21;
const ld EPS = 1e-9; 

int par[MAX];
vi adj[MAX];
bool act[MAX], vis[MAX];
int N, ans = INT_MAX;
vi v(N), dp(1 << MAX, INT_MAX);

bool cy(int u) {
	bool b = 0;
	act[u] = 1;
	for (auto v : adj[u]) {
		if (act[v]) return 1;
		b |= cy(v);
	}
	act[u] = 0;
	return b;
} 

int dfs(int t, int av, int did) {
	if (dp[did] != INT_MAX) return dp[did]+t;
	int dd = did;
	for (int i = 0; i < N; ++i) {
		if ((1 << i) & did) continue;
		int x = __builtin_popcount(did & par[i]), y = __builtin_popcount(par[i]);
		if (__builtin_popcount(did & par[i]) == __builtin_popcount(par[i])) av |= (1 << i);
	}
	if (did == (1 << N)-1) {
		ans = min(ans, t);
		return t;
	}
	vi v2;
	dd = av;
	while (dd) {
		int i = __builtin_ctz(dd);
		v2.pb(i);
		dd &= (dd-1); 
	}
	int rm = INT_MAX;
	for (int i = 0; i < v2.size(); ++i) {
		int x = av, y = did;
		x &= ~(1 << v2[i]);
		y |= (1 << v2[i]);
		rm = min(rm, dfs(t + v[v2[i]], x, y));
		for (int j = i+1; j < v2.size(); ++j) {
			x = av, y = did;
			x &= ~(1 << v2[i]);
			x &= ~(1 << v2[j]);
			y |= (1 << v2[i]);
			y |= (1 << v2[j]);
			rm = min(rm, dfs(t + max(v[v2[i]], v[v2[j]]), x, y));
		}
	}
	dp[did] = min(dp[did], rm-t);
	return rm;
}

void solve() {
    cin >> N;
	v.resize(N);
    for (auto& x : v) cin >> x;
    for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			int x; cin >> x;
			if (x) adj[j].pb(i);
			if (x) par[i] |= (1 << j);
		}
	int av = 0;
	for (int i = 0; i < N; ++i)
		if (cy(i)) {
			cout << -1 << '\n';
			return;
		} else if (!par[i]) {
			av |= (1 << i);
		}
	ans = min(ans, dfs(0, av, 0));
	cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
