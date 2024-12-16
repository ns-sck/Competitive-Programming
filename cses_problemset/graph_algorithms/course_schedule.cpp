#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> top;
    vector<bool> vis(N + 1);
    vector<int> pos(N + 1);
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    std::function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
        pos[u] = top.size();
        top.emplace_back(u);
    };
    for (int i = 1; i <= N; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(top.begin(), top.end());
    bool ok = top.size() == N;
    for (int i = 1; i <= N && ok; ++i) {
        for (auto v : adj[i]) {
            if (pos[v] >= pos[i]) {
                ok = false;
                break;
            }
        }
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int& x : top) {
            cout << x << ' ';
        }
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