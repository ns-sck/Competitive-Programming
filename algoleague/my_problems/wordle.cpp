#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

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
const ll INF = 1e12;
const ll MAX = 1e5+1;

vpi adj[MAX], rev[MAX];
int src[6];
int dis[6][5];
map<int, int> conv;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    src[5] = 1;
    conv[1] = 5;

    for (int i = 0; i < 5; ++i) {
        cin >> src[i];
        conv[src[i]] = i;
    }

    auto dijkstra = [&](int u) {
        priority_queue<pi, vpi, greater<>> pq;
        vi dist(N+1, INF);
        pq.push({0, u});

        while (pq.size()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dist[v] <= d) continue;
            dist[v] = d;
            for (auto [x, w] : adj[v]) {
                if (d + w < dist[x]) pq.push({d + w, x});
            }
        }

        for (int i = 0; i < 5; ++i) dis[conv[u]][i] = dist[src[i]];
    };

    dijkstra(1);
    for (int i = 0; i < 5; ++i) dijkstra(src[i]);

    int ans = INF;
    vi v(5);
    iota(all(v), 0);

    do {
        int cost = dis[5][v[0]];
        int diff = v[0] != 0;
    
        for (int i = 1; i < 5; ++i) {
            cost += dis[v[i-1]][v[i]];
            diff += v[i] != i;
        }

        cost += dis[5][v[4]];
        if (diff == 0) { ans = min(ans, cost); }
        else ans = min(ans, cost + (diff - 1) * K);

    } while (next_permutation(all(v)));

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    auto start = high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);
    // cout << "Time taken: " << duration.count() << " ms" << '\n';

    return 0;
}
