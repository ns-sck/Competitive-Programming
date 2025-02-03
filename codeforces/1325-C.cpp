#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> adj(N);
  vector<int> ans(N - 1, -1);
  int leaf = -1, root = -1;
  if (N == 3) {
    cout << 0 << '\n' << 1 << '\n';
    return;
  }
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
  }
  for (int i = 0; i < N; ++i) {
    if (adj[i].size() == 1) {
      if (leaf == -1) leaf = i;
      else if (root == -1) root = i;
    }
  }
  int c = 2;
  auto dfs = [&](auto&& self, int u, int p) -> bool {
    bool b = u == leaf;
    for (auto& [v, i] : adj[u]) {
      if (v == p) continue;
      if (self(self, v, u)) {
        b = 1;
        if (u == root) ans[i] = 0;
        else ans[i] = c++ % (N - 1);
      }
    }
    return b;
  };
  dfs(dfs, root, -1);
  for (int i = 0; i < N - 1; ++i) {
    if (ans[i] == -1) {
      if (c < N - 1) ans[i] = c++;
      else ans[i] = 1;
    }
  }
  for (auto& x : ans) cout << x << '\n';
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