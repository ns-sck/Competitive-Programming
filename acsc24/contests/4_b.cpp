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
int in[MAX], out[MAX], timer, par[MAX][19], dis[MAX];

void dfs(int u = 1, int p = 1, int d = 0) {
    in[u] = ++timer;
    dis[u] = d;
    if (~p) par[u][0] = p; 
    for (int i = 1; i < 19; ++i) {
        par[u][i] = par[par[u][i-1]][i-1]; 
    }
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d+1);
    }
    out[u] = ++timer;
}

bool isanc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v]; 
}

int lca(int u, int v) {
    if (isanc(u, v)) return u;
    if (isanc(v, u)) return v;
    for (int i = 18; ~i; --i) {
        if (!isanc(par[u][i], v))
            u = par[u][i];
    }
    return par[u][0];
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    while (--N) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    while (Q--) {
        int u, v;
        cin >> u >> v;
        int l = lca(u, v);
        cout << l << ' ' << dis[u] + dis[v] - 2*dis[l] << '\n';
    }
    
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
