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
const ld EPS = 1e-9; 

vi adj[MAX];
int N, M, tin[MAX], low[MAX], c = -1;
bool vis[MAX];

void bridge(int u, int p = -1) {
    vis[u] = 1;
    tin[u] = low[u] = ++c;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            bridge(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                cout << u << ' ' << v << '\n';
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bridge(0);
    cout << 1;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
