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
vvi adj[MAX];
vi adj[MAX];
vi d(MAX, INF);
void solve() {
    int N, M;
    cin >> N >> M;
    while (M--) {
        int u, v, t, k;
        cin >> u >> v >> t >> k;
        adj[u].pb({v,t,k});
        adj[v].pb({u,t,k});
    }
    priority_queue<pi, vpi, greater<>> pq;
    pq.push({0, 1});
    while (pq.size()) {
        auto [dis, u] = pq.top();
        pq.pop();
        if (d[u] < dis) continue;
        d[u] = dis;
        for (auto& vv : adj[u]) {
            int v = vv[0], t = vv[1], k = vv[2];
            int wt = dis%k == 0 ? 0 : k-(dis%k);
            if (wt+dis+t < d[v])
                pq.push({wt+dis+t, v});
        }
    }
    if (d[N] == INF) cout << -1;
    else cout << d[N];
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
