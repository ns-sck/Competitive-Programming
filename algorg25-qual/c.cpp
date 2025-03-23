#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int& x : a) cin >> x;
  for (int & x : b) cin >> x;
  vector<vector<int>> dp(N + 1, vector<int>(N + 1));
  dp[0][0] = a[0] == b[0];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      }
      if (j) {
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      }
      if (a[i] == b[j]) {
        if (i) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + (i + 1) * (j + 1));
        }
        if (j) {
          dp[i][j] = max(dp[i][j], dp[i][j - 1] + (i + 1) * (j + 1));
        }
      }
    }
  }
  cout << dp[N - 1][N - 1] << '\n';
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