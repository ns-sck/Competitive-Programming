#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> grid(N, vector<int>(N));
  vector<int> dp(1 << N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < (1 << N); ++i) {
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) continue;
      int mask = i | (1 << j);
      int row = __builtin_popcount(i);
      dp[mask] = max(dp[mask], dp[i] + grid[row][j]);
    }
  }
  cout << dp[(1 << N) - 1] << '\n';
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