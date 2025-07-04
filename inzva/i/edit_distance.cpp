#include <bits/stdc++.h>
using namespace std;

#define int int64_t

//https://cses.fi/problemset/task/1639

void solve() {
  string A, B;
  cin >> A >> B;
  int n = A.size(), m = B.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1ll << 61));
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; ++j) {
    dp[0][j] = j;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      // if the i'th letter of the first string and
      // j'th letter of the second string are the same
      // we can simply say that we need at most dp[i - 1][j - 1] operations
      // and then add these letters without an operation
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      // option1: adding a letter to the second string
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      // option2: adding a letter to the first string (adding to second = removing from the first)
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      // option3: changing a letter from one of the strings
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
    }
  }
  cout << dp[n][m] << '\n';
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