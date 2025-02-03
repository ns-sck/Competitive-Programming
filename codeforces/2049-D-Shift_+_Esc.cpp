#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> grid(N + 1, vector<int>(M + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> grid[i][j];
    }
  }
  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(M, 1ll << 61)));
  vector<vector<int>> best(N + 1, vector<int>(M + 1, 1ll << 61));
  best[0][1] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      for (int k = 0; k < M; ++k) {
        int idx = j + k;
        if (idx > M) idx = (idx % (M + 1)) + 1;
        dp[i][j][k] = best[i - 1][j] + grid[i][idx] + k * K;
      }
    }
    for (int j = 2; j <= M; ++j) {
      for (int k = 0; k < M; ++k) {
        int idx = j + k;
        if (idx > M) idx = (idx % (M + 1)) + 1;
        dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k] + grid[i][idx]);
      }
    }
    for (int j = 1; j <= M; ++j) {
      for (int k = 0; k < M; ++k) {
        best[i][j] = min(best[i][j], dp[i][j][k]);
      }
    }
  }
  cout << best[N][M] << '\n';
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