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
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vi d1(N+1, INF), d2(N+1, INF), dA(N+1, INF), dB(N+1, INF), dN(N+1, INF);

    auto dijkstra = [&](int src, int m, vi& d) {

        priority_queue<pi, vpi, greater<>> pq;
        pq.push({0, src});

        while (pq.size()) {
            auto [dis, u] = pq.top();
            pq.pop();

            if (d[u] < dis) continue;
            d[u] = dis;

            for (auto [v, w] : adj[u]) {
                if (dis + w / m < d[v]) pq.push({dis + w / m, d[v]});
            }
        }
    };

    dijkstra(A, 1, dA);
    dijkstra(B, 1, dB);
    dijkstra(N, 3, dN);

    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<>> pq;
    pq.push({0, 1, 0});

    while (pq.size()) {
        auto [dis, u, b] = pq.top();
        pq.pop();

        if (b) {
            if (d2[u] < dis) continue;
            d2[u] = dis;
            for (auto [v, w] : adj[u]) {
                if (dis + (w / 2) < dA[v]) pq.push({dis + w / 2, v, 1});
            }
        } else {
            if (d1[u] < dis) continue;
            d1[u] = dis;
            for (auto [v, w] : adj[u]) {
                if (max(dis, dA[u]) + (w / 2) < dA[v]) pq.push({max(dis, dA[u]) + (w / 2), v, 1});
                if (dis + w < d1[v]) pq.push({dis + w, v, 0});
            }
        }
    }
        
    int ans = INF;

    for (int i = 1; i <= N; ++i) {
        ans = min(ans, max(d2[i], dB[i]) + dN[i]);
    }
    
    cout << ans << '\n';
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
