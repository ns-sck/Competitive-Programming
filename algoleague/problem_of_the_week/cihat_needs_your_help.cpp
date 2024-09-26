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

void solve() {
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vvi dis(N+1, vi(2, INF));

    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<>> pq;

    pq.push({0, 1, 1});

    while (pq.size()) {
        auto [d, u, b] = pq.top();
        pq.pop();

        if (dis[u][b] <= d) continue;
        dis[u][b] = d;

        for (auto [v, w] : adj[u]) {
            if (d + w < dis[v][b]) pq.push({d + w, v, b});
            if (b && d + (w >> 1) < dis[v][0]) pq.push({d + (w >> 1), v, 0});
        }
    }

    if (dis[N][0] ^ INF) cout << dis[N][0] << '\n';
    else cout << -1 << '\n';
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
