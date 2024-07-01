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

vpi adj[MAX];
set<int> adj2[MAX];
int N, M, tin[MAX], low[MAX], clr[MAX], c = -1;
bool vis[MAX], isbr[MAX], vis2[MAX];
vvi edg;

void bridge(int u, int p = -1) {
    vis2[u] = 1;
    tin[u] = low[u] = ++c;
    bool skp = 0;
    for (auto& pr : adj[u]) {
        auto [v, idx] = pr;
        if (v == p) { continue; }
        if (vis2[v]) {
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

bool vis3[MAX];
void solve() {
    cin >> N >> M;
    int ei = 0;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, ei});
        adj[v].pb({u, ei});
        edg.pb({u, v, ei});
        edg.pb({v, u, ei});
        ++ei;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (vis2[i]) continue;
        bridge(i);
    }
    for (auto& v : edg) {
        int u = v[0], u2 = v[1], idx = v[2];
        if (!isbr[idx]) { adj2[u].insert(u2); adj2[u2].insert(u); }
    }
    int cntr = 0;
    for (int i = 0; i < N; ++i) {
        if (vis3[i]) continue;
        bool b = 0;
        int ncnt = 0;
        queue<pi> q;
        q.push({i, 1});
        while (q.size()) {
            auto [u, cl] = q.front();
            q.pop();
            if (vis3[u]) continue;
            ++ncnt;
            ++cntr;
            vis3[u] = 1;
            clr[u] = cl;
            for (auto& v : adj2[u]) {
                if (clr[v] == clr[u]) b = 1;
                q.push({v, -cl});
            }
        }
        if (b) ans += ncnt;
    }
    assert(cntr == N);
    cout << ans << '\n';

}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
