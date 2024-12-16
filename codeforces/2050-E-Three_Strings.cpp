#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string A, B, C;
  cin >> A >> B >> C;
  int a = A.size(), b = B.size(), c = C.size();
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
  dp[0][0] = 0;
  dp[0][1] = C[0] == B[0] ? 0 : 1;
  dp[1][0] = C[0] == A[0] ? 0 : 1;
  for (int i = 1; i <= a; ++i) {
    dp[i][0] = dp[i - 1][0] + (C[i - 1] != A[i - 1]);
  }
  for (int i = 1; i <= b; ++i) {
    dp[0][i] = dp[0][i - 1] + (C[i - 1] != B[i - 1]);
  }
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + (A[i - 1] != C[i + j - 1]));
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + (B[j - 1] != C[i + j - 1]));
    }
  }
  cout << dp[a][b] << '\n';
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