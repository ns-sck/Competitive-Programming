#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;
int dp[20][1 << 20];
bool vis[20][1 << 20];

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);  
  }
  dp[0][1] = 1;
  queue<pair<int, int>> q;
  q.push({0, 1});
  while (q.size()) {
    auto [u, msk] = q.front();
    q.pop();
    if (u != N - 1) {
      for (int& v : adj[u]) {
        if ((msk >> v) & 1) continue;
        int nmsk = msk | (1 << v);
        dp[v][nmsk] += dp[u][msk];
        dp[v][nmsk] %= MOD;
        if (!vis[v][nmsk]) {
          vis[v][nmsk] = 1;
          q.push({v, nmsk});
        }
      }
    }
  }
  cout << dp[N - 1][(1 << N) - 1] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}