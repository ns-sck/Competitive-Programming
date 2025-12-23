#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;
map<pair<int, int>, int> dp;
map<pair<int, int>, bool> vis;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(64);
  array<int, 2> d[8] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      for (auto [a, b] : d) {
        int ii = i + a, jj = j + b;
        if (ii >= 0 && ii < 8 && jj >= 0 && jj < 8) {
          adj[i * 8 + j].push_back(ii * 8 + jj);
        }
      }
    }
  }
  dp[{N * 8 + M, 1ll << (N * 8 + M)}] = 1;
  queue<pair<int, int>> q;
  q.push({0, 1});
  while (q.size()) {
    auto [u, msk] = q.front();
    q.pop();
    if (q.size() > 1e6) {
      cout << "GG";
      exit(0);
    }
    for (int& v : adj[u]) {
      if ((msk >> v) & 1) continue;
      int nmsk = msk | (1 << v);
      dp[{v, nmsk}] += dp[{u, nmsk}];
      dp[{v, nmsk}] %= MOD;
      if (!vis[{v, nmsk}]) {
        vis[{v, nmsk}] = 1;
        q.push({v, nmsk});
      }
    }
  }
  cout << dp[{N - 1, 1ll << 63}] << '\n';
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