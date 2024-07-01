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

vi adj[MAX];
bool m[MAX];
int ans = 0;

void dfs(int u = 1, int par = -1) {
    for (auto v : adj[u]) {
        if (v ^ par) dfs(v, u);
    }
    if (~par && !m[u] && !m[par]) {
        m[u] = 1, m[par] = 1;
        ++ans;
    }
}

void solve() {
    int N; cin >> N;
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
