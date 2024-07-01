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
const ll MAX = 5e3+1;
const ld EPS = 1e-9; 

vi adj[MAX];
int dp[MAX][MAX];
int d[MAX][MAX];
int sz[MAX];
int N, M;

void dfs2(int u = 1, int p = -1) {
    sz[u] = 1;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
        sz[u] += sz[v];
    }
    dp[u][0] = adj[u].size() - (p != -1);
}

void dfs(int u = 1, int p = -1) {
    int x = 0;
    for (auto& v : adj[u]) {

        if (v == p) continue;
        dfs(v, u);

        for (int i = 1; i <= M; ++i) {
            dp[u][i] = max(dp[u][i], dp[v][i-1]);
        }
        for (int i = 1; i <= M; ++i) {
            if (i > x) break;
            for (int j = 1; j <= M; ++j) {
                if (i+j > M || j > sz[v]) break;
                dp[u][i+j] = max(dp[u][i+j], dp[v][j-1] + dp[u][i]);
            }
        }
        for (int i = 0; i <= M; ++i) {
            d[u][i] = max(d[u][i], dp[u][i]);
        }
        x += sz[v];
    }
}

void solve() {

    cin >> N >> M;
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs2();
    dfs();
    cout << dp[1][M];
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
