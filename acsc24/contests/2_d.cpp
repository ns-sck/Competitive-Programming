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
const ll MAX = 20;
const ld EPS = 1e-9; 

vpi adj[MAX];
vi adj2[MAX];
int cmp[MAX];
bool isbr[MAX];
int tin[MAX], low[MAX], timer = 0;
bool vis[MAX], vis2[MAX];
int ncnt = 0, dst = 0, dw[MAX];

void bridge(int u, int p = -1) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    bool skip = 0;
    for (auto& pr : adj[u]) {
        auto [v, idx] = pr;
        if (v == p && skip == 0) { skip = 1; continue; }
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            bridge(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                isbr[idx] = 1;
            }
        }
    }
}

void dfs(int u, int p) {
    vis2[u] = 1;
    int j = ncnt;
    for (auto& pr : adj[u]) {
        auto [v, idx] = pr;
        if (v == p || vis2[v]) continue;
        if (isbr[idx]) {
            adj2[j].pb(ncnt+1);
            ++ncnt;
        }
        dfs(v, u);
    }
}

void tdst(int u, int p) {
    int mx1 = -1, mx2 = -1;
    for (auto& v : adj2[u]) {
        if (v == p) continue;
        tdst(v, u);
        if (mx1 == -1 || dw[v] >= dw[mx1]) {
            mx2 = mx1;
            mx1 = v;
        } else if (mx2 == -1 || dw[v] > dw[mx2]) mx2 = v;
        dw[u] = max(dw[u], dw[v]+1);
    }
    dst = max({dst, (mx1 == -1 ? 0 : dw[mx1]+1) + (mx2 == -1 ? 0 : dw[mx2]+1), dw[u]});
}

void solve() {
    int N, M;
    cin >> N >> M;
    int j = 0;
    while (M--) {
        int u, v;
        cin >> u >> v;
        ++u, ++v;
        adj[u].pb({v, j}); 
        adj[v].pb({u, j}); 
        j++;
    }
    int ans = 0, c = 0;
    for (int i = 1; i <= N; ++i) {
        if (vis2[i]) continue;
        ++c;
        bridge(i);
        int k = ncnt;
        dfs(i, -1);
        tdst(k, -1);
        ++ncnt;
        ans += dst;
        dst = 0;
    }

    cout << ans+c-1 << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
