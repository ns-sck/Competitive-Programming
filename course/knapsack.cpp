#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, T;
  cin >> N >> T;
  vector<int> weights(N), profits(N);
  for (int& x : weights) cin >> x;
  for (int& x : profits) cin >> x;
  vector<int> dp(T + 1);
  // i'th eleman with j money
  for (int i = 0; i < N; ++i) {
    for (int j = T; j >= 0; --j) {
      if (j >= weights[i]) {
        dp[j] = max(dp[j], dp[j - weights[i]] + profits[i]);
      }
    }
  }
  cout << dp[T] << '\n';
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