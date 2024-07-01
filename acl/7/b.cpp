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
const ll MAX = 1e3+1;

int N, M, src, dst, l[MAX], c[MAX];
vpi adj[MAX];
vi dist(MAX, INF), came(MAX, -1), start(MAX, -1);
void solve() {
    cin >> N >> M >> src >> dst;
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        l[i] = a, c[i] = b;
    }
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    if (src == dst) {
        cout << 0 << '\n';
        exit(0);
    }

    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<>> pq;
    pq.push({c[src], l[src], src});
    came[src] = 0;
    while (pq.size()) {
        auto [dis, left, u] = pq.top();
        pq.pop();
        dist[u] = min(dist[u], dis);
        for (auto& [v, w] : adj[u]) {
            if (dis < dist[v] && left-w >= 0) {
                pq.push({dis, left-w, v});
            } else if (left-w > came[v]) { pq.push({dis, left-w, v}); came[v] = left-w; }
            if (start[v] < left-w && left-w >= 0) {
                start[v] = left-w;
                pq.push({dis+c[v], l[v], v});
            }
        }
    }
    if (dist[dst] == INF) cout << -1;
    else cout << dist[dst];
}   

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
