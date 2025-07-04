#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N), adj2(N);
  while (M--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj2[v].push_back(u);
  }
  vector<bool> vis(N), vis2(N);
  auto dfs = [&](auto&& self, int u, int p, vector<bool>& seen, vector<vector<int>>& g) -> void {
    seen[u] = 1;
    for (int& v : g[u]) {
      if (v != p && !seen[v]) {
        self(self, v, u, seen, g);
      }
    }
  };
  dfs(dfs, 0, -1, vis, adj);
  dfs(dfs, 0, -1, vis2, adj2);
  for (int i = 0; i < N; ++i) {
    if (!vis[i] || !vis2[i]) {
      cout << "NO\n";
      if (!vis[i]) {
        cout << 1 << ' ' << i + 1 << '\n';
      } else {
        cout << i + 1 << ' ' << 1 << '\n';
      }
      return;
    }
  }
  cout << "YES\n";
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