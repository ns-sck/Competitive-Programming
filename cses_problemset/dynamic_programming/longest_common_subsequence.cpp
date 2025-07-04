#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;
  vector<vector<int>> dp(N + 1, vector<int>(M + 1));
  vector<vector<int>> par(N + 1, vector<int>(M + 1));
  for (int i = 0; i < N; ++i) {
    par[i + 1][0] = 1;
    for (int j = 0; j < M; ++j) {
      par[0][j + 1] = 2;
      dp[i + 1][j + 1] = dp[i][j + 1];
      par[i + 1][j + 1] = 1;
      if (dp[i + 1][j] > dp[i + 1][j + 1]) {
        dp[i + 1][j + 1] = dp[i + 1][j];
        par[i + 1][j + 1] = 2;
      }
      if (a[i] == b[j] && dp[i][j] + 1 > dp[i + 1][j + 1]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
        par[i + 1][j + 1] = 3;
      }
    }
  }
  vector<int> ans;
  cout << dp[N][M] << '\n';
  while (N || M) {
    if (par[N][M] == 1) {
      N--;
    } else if (par[N][M] == 2) {
      M--;
    } else {
      ans.push_back(a[N - 1]);
      N--, M--;
    }
  }
  reverse(ans.begin(), ans.end());
  for (int& x : ans) cout << x << ' ';
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