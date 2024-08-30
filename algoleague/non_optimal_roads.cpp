#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
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
vi dis(MAX, INF);
vi dis2(MAX, INF);

void solve() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    vvi edg(M, vi(3));
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edg[i] = {u, v, w};
    }

    priority_queue<pi, vpi, greater<>> pq;
    pq.push({0, S});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] <= d) continue;
        dis[u] = d;
        for (auto [v, w] : adj[u]) {
            if (w+d < dis[v]) pq.push({w+d, v});
        }
    }

    pq.push({0, T});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis2[u] <= d) continue;
        dis2[u] = d;
        for (auto [v, w] : adj[u]) {
            if (w+d < dis2[v]) pq.push({w+d, v});
        }
    }

    vi ans;

    for (int i = 0; i < M; ++i) {
        int u = edg[i][0], v = edg[i][1], w = edg[i][2];
        if (dis[u] + dis2[v] + w == dis[T] || dis[v] + dis2[u] + w == dis[T]) continue;
        ans.pb(i+1);
    }
    cout << ans.size() << '\n';
    for (int& x : ans) cout << x << ' ';
}

signed main () {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
