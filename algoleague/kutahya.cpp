#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<array<int, 2>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  vector<bool> vis(N), isbr(M * 3);
  vector<int> tin(N), low(N);
  int timer = 0;
  auto bridge = [&](auto&&self, int u, int p) -> void {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    bool skip = 0;
    for (auto [v, idx] : adj[u]) {
      if (v == p) {
        skip = 1;
        continue;
      }
      if (vis[v]) {
        low[u] = min(low[u], tin[v]);
      } else {
        self(self, v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] > tin[u]) {
          isbr[idx] = 1;
        }
      }
    }
  };
  for (int i = 0; i < N; ++i) {
    if (vis[i]) continue;
    timer = 0;
    bridge(bridge, i, -1);
  }
  vis.assign(N, 0);
  int node = -1, best = -1;
  vector<int> stack;
  auto dfs = [&](auto&& self, int u, int p, int cnt) -> void {
    vis[u] = 1;
    stack.emplace_back(u);
    if (cnt > best) {
      best = cnt;
      node = u;
    }
    for (auto& [v, idx] : adj[u]) {
      if (v == p || vis[v]) continue;
      self(self, v, u, cnt + isbr[idx]);
    }
  };
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (vis[i]) continue;
    best = -1, node = -1;
    ++ans;
    stack.clear();
    dfs(dfs, i, -1, 0);
    for (auto& u : stack) {
      vis[u] = 0;
    }
    dfs(dfs, node, -1, 0);
    ans += best;
  }
  cout << ans - 1 << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}