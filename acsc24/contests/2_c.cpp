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
const ll MAX = 20;
const ld EPS = 1e-9; 
vpi adj[MAX];
vvi dis(MAX, vi(2, INF));
bool br[MAX];
void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    int src, dst;
    cin >> src >> dst;
    while (K--) {
        int u; cin >> u;
        br[u] = 1;
    }
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    priority_queue<vi, vvi, greater<>> pq;
    pq.push({0, src, br[src]});
    while (pq.size()) {
        vi v = pq.top();
        pq.pop();
        int d = v[0], u = v[1], ok = v[2];
        ok = max(ok, (ll)br[u]);
        if (dis[u][ok] < d) continue;
        dis[u][ok] = d;
        for (auto& pr : adj[u]) {
            auto [v, w] = pr;
            if (d + w < dis[v][ok]) {
                pq.push({d+w, v, ok});
            }
        }
    }
    if (dis[dst][1] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dis[dst][1] << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
