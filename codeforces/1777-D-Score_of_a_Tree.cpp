#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int c = 1;
  for (int i = 0; i < N - 1; ++i) {
    c = c * 2 % MOD;
  }
  vector<int> h(N);
  int ans = 0;
  auto dfs = [&](auto&& self, int u, int p) -> void {
    int mx = 0;
    for (int& v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      mx = max(mx, h[v]);
    }
    h[u] = mx + 1;
    debug(h[u], c);
    ans = (c * h[u] + ans) % MOD;
  };
  dfs(dfs, 0, -1);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}