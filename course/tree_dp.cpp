#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> points(N);
  for (int& x : points) cin >> x;
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<vector<int>> dp(N, vector<int>(2, 0));
  auto dfs = [&](auto&& self, int u, int p) -> void {
    if (adj[u].size() == 1 && p != -1) {
      dp[u][1] = points[u];
      dp[u][0] = 0;
      return;
    }
    int empty = 0;
    int x = 0;
    for (int& v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      empty += dp[v][0];
      x += max(dp[v][0], dp[v][1]);
    }
    dp[u][1] = empty + points[u];
    dp[u][0] = x;
  };
  dfs(dfs, 0, -1);
  // 0 = root;
  cout << max(dp[0][0], dp[0][1]) << '\n';
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