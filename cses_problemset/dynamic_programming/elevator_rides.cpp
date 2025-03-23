#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, X;
  cin >> N >> X;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<int> dp(1 << N, 1ll << 57);
  dp[0] = 0;
  for (int i = 0; i < (1 << N); ++i) {
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) continue;
      int msk = i | (1 << j);
      int has = dp[i] / X;
      if (X - (dp[i] % X) >= arr[j]) {
        dp[msk] = min(dp[msk], dp[i] + arr[j]);
      } else {
        dp[msk] = min(dp[msk], (has + 1) * X + arr[j]);
      }
    }
  }
  cout << (dp[(1 << N) - 1] + X - 1) / X << '\n';
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