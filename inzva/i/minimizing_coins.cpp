#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// https://cses.fi/problemset/task/1634

void solve() {
  int N, X;
  cin >> N >> X;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  // dp[i] holds minimum number of coins to reach the sum i
  vector<int> dp(X + 1, 1ll << 61);
  dp[0] = 0;
  for (int i = 1; i <= X; ++i) {
    for (int& coin : arr) {
      if (i >= coin) {
        // we can reach dp[i - coin] times to the sum (i - coin)
        // use 1 more coin and reach the sum i
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }
  if (dp[X] == 1ll << 61) dp[X] = -1;
  cout << dp[X] << '\n';
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