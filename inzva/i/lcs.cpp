#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string A, B;
  cin >> A >> B;
  int n = A.size(), m = B.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      // we have at least dp[i][j] common subsequence
      // either not using the i'th letter of the first string
      // or not using the j'th letter of the second string 
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      // if i'th letter of the first string and j'th letter
      // of the second string are the same, we can also have
      // 1 letter more from the state where we have only i - 1 and j - 1 letters
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
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