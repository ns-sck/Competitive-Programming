#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> dp(N + 1);
  dp[0] = 0, dp[1] = 1;
  for (int i = 2; i <= N; ++i) {
    // fib(x) = fib(x - 1) + fib(x - 2)
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[N] << '\n';
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