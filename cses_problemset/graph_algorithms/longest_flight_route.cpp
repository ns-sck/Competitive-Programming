#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;
// was much easier with indegree count
void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> par(N + 1, -1);
    vector<set<int>> adj(N + 1);
    vector<int> dis(N + 1, 0);
    vector<int> top;
    vector<int> pos(N + 1);
    vector<bool> vis(N + 1);
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace(v);
    }
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
        pos[u] = top.size();
        top.emplace_back(u);
    };
    dfs(1);
    priority_queue<pair<int, int>> pq;
    dis[1] = 1;
    pq.emplace(0, 1);
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        for (auto v : adj[u]) {
            if (dis[v] < dis[u] + 1) {
                dis[v] = dis[u] + 1;
                pq.emplace(pos[v], v);
                par[v] = u;
            }
        } 
    }
    if (dis[N] == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        int u = N;
        vector<int> path;
        while (u != -1) {
            path.emplace_back(u);
            u = par[u];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (int& x : path) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}