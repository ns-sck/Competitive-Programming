#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  int ans = 0;
  vector<int> sz(N);
  auto dfs = [&](auto&&self, int u, int p) -> void {
    bool b = 1;
    int s = -1;
    sz[u] = 1;
    for (auto& v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      if (s == -1) {
        s = sz[v];
      } else {
        if (sz[v] != s) {
          b = 0;
        }
      }
      sz[u] += sz[v];
    }
    ans += b;
  };
  dfs(dfs, 0, -1);
  cout << ans << '\n';
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