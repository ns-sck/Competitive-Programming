#include <bits/stdc++.h>
using namespace std;

#define int int64_t

vector<int> dp;
vector<int> dp2;
vector<vector<int>> adj;
int leaf = -1;

void dfs(int u = 1, int p = -1) {
  dp[u] = adj[u].size();
  bool b = 0;
  int mx1 = 0, mx2 = 0;
  for (auto v : adj[u]) {
    if (v == p) continue;
    b = 1;
    dfs(v, u);
    int x = dp[v] - 1 + adj[u].size() - 1;
    dp[u] = max(dp[u], x);
    if (dp[v] >= mx1) {
      mx2 = mx1;
      mx1 = dp[v];
    } else if (dp[v] > mx2) {
      mx2 = dp[v];
    }
  }
  int z = mx1 - 1 + mx2 - 1 + (adj[u].size() - 2);
  dp2[u] = max(dp[u], z);
  if (!b) leaf = u;
}

void solve() {
  int N;
  cin >> N;
  dp.assign(N + 1, 0);
  dp2.assign(N + 1, 0);
  adj.assign(N + 1, {});
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs();
  if (~leaf) dfs(leaf);
  int ans = *max_element(dp2.begin(), dp2.end());
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}