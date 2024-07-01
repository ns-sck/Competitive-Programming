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
const ll MAX = 4;
const ld EPS = 1e-9; 

vpi adj[MAX];
int N, M, tin[MAX], low[MAX], c = 0;
bool vis[MAX];
map<int, int> mp;
map<pi, bool> mp2;
int eb = 0;

void bridge(int u, int p = -1) {
    vis[u] = 1;
    tin[u] = low[u] = c++;
    bool skip = 0;
    for (auto& pr : adj[u]) {
        auto [v, w] = pr; 
        if (v == p && !skip) {
            skip = 1;
            continue;
        }
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            bridge(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                mp2[{u, v}] = 1;
                mp2[{v, u}] = 1;
            }
        }
    }
}

void solve() {
    cin >> N;
    vvi edg;
    while (N--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edg.pb({u, v, w});
    }
    bridge(1);
    for (auto& e : edg) {
        int u = e[0], v = e[1], w = e[2];
        if (mp2[{u, v}]) continue;
        ++mp[w];
    } 
    auto it = mp.end();
    --it;
    cout << it->second << '\n'; 
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
