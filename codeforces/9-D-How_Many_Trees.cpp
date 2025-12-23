#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, H;
  cin >> N >> H;
  vector<vector<int>> dp(N + 1, vector<int>(N + 1));
  dp[0][0] = dp[1][1] = 1;
  for (int i = 2; i <= N; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int jh = 0; jh <= j; ++jh) {
        for (int kh = 0; kh <= i - j - 1; ++kh) {
          dp[i][max(kh, jh) + 1] += dp[j][jh] * dp[i - j - 1][kh];
        }
      }
    }
  }
  int ans = 0;
  for (int i = H; i <= N; ++i) {
    ans += dp[N][i];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}