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

vpi adj[MAX];
vi d(MAX, INF);

void solve() {
    int N, M;
    cin >> N >> M;
    int src, dst;
    cin >> src >> dst;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<>> pq;

    pq.push({0, src});
    ll ans = INF;
    while (pq.size()) {
        auto [mx, u] = pq.top();
        pq.pop();
        if (d[u] < mx) continue;
        if (u == dst) {
            ans = min(ans, mx);
        }
        d[u] = mx;
        for (auto& [v, w] : adj[u]) {
            int mxx = max(mx, w);
            if (d[v] <= mxx) continue;
            else {
                int mxx = max(mx, w);
                pq.push({mxx, v});
            }
        }
    }

    cout << ans;
}   

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
