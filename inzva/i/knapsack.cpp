#include <bits/stdc++.h>
using namespace std;

#define int int64_t

/*
5 100
30 20 50 70 40
40 10 80 60 20
*/
void solve() {
  int N, W;
  cin >> N >> W;
  vector<int> weight(N + 1), profit(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> weight[i];
  }
  for (int i = 1; i <= N; ++i) {
    cin >> profit[i];
  }
  vector<vector<int>> dp(N + 1, vector<int>(W + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= W; ++j) {
      // with current money and using only current items
      // we can reach at least profit dp[i][j], by not considering the current item (dp[i - 1][j])
      // or using 1 less money (dp[i][j - 1])
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (j >= weight[i]) {
        // take this item, and go to the state where we have
        // weight[i] less money and considering only i - 1 items
        // and add current item's profit
        dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + profit[i]);
      }
    }
  }
  cout << dp[N][W] << '\n';
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