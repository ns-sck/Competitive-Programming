#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;
void solve() {
  int N, M;
  cin >> N >> M;
  if (N == 1) {
    cout << (~M & 1) << '\n';
    return;
  }
  vector<vector<int>> dp(M + 1, vector<int>(1 << N));
  dp[0][0] = 1;
  vector<vector<int>> match(1 << N);
  for (int i = 0; i < (1 << N); ++i) {
    for (int j = 0; j < (1 << N); ++j) {
      if (j & i) continue;
      int ii = 0, jj = j;
      while (jj) {
        ii |= jj & -jj;
        jj -= jj & -jj;
      }
      bool bad = 0;
      for (int k = 0; k < N; ++k) {
        if (((i | j) >> k) & 1) continue;
        bad |= k == N - 1;
        bad |= ((i | ii) >> (k + 1)) & 1;
        k++;
      }
      if (!bad) match[i].push_back(j);
    }
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < (1 << N); ++j) {
      for (int& k : match[j]) {
        dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
      }
    }
  }
  cout << dp[M][0] << '\n';
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