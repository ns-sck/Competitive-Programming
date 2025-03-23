#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 232323233;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N, vector<int>(5));
  vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(5));
  while (M--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    g[i][j] = 1;
  }
  int mx = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (i == 0) {
        dp[i][j] = {g[i][j], 1};
      } else {
        for (int a : {-1, 0, 1}) {
          int x = j + a;
          if (x < 0 || x >= 5) continue;
          if (dp[i - 1][x].first > dp[i][j].first) {
            dp[i][j] = dp[i - 1][x];
          } else if (dp[i - 1][x].first >= dp[i][j].first) {
            dp[i][j].second = (dp[i][j].second + dp[i - 1][x].second) % MOD;
          }
        }
        if (g[i][j]) dp[i][j].first++;
      }
      mx = max(mx, dp[i][j].first);
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    if (dp[N - 1][i].first == mx) {
      ans = (ans + dp[N - 1][i].second) % MOD;
    }
  }
  cout << mx << ' ' << ans << '\n';
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