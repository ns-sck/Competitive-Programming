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
const ll MAX = 1e5+5;
const ld EPS = 1e-9; 

vi adj[MAX];
int sz[MAX], N, ans = 0;

void dfs(int u = 1, int p = -1) {
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u = 1, int p = -1) {
    int bs = 0;

    for (auto v : adj[u]) {
        if (p == v) continue;
        if (sz[v] >= sz[bs]) bs = v;
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (sz[v]*2 >= N) dfs2(v, u);
    }
    if (sz[bs]*2 <= N) ++ans;
}
void solve() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    dfs2();
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
