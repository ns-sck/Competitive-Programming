#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  K >>= 1;
  vector<vector<int>> dp(N, vector<int>(K + 1));
  auto dfs = [&](auto&& self, int u, int p) -> void {
    dp[u][0] = arr[u];
    if (adj[u].size() == 1 && p != -1) {
      return;
    }
    vector<int> temp = dp[u];
    for (auto& v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      for (int i = 1; i <= K; ++i) {
        for (int j = 0; j < i; ++j) {
          temp[i] = max(temp[i], dp[u][j] + dp[v][i - j - 1]);
        }
      }
      dp[u] = temp;
    }
  };
  dfs(dfs, 0, -1);
  cout << *max_element(dp[0].begin(), dp[0].end()) << '\n';
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