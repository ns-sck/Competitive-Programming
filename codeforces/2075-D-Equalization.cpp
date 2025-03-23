#include <bits/stdc++.h>
using namespace std;

#define int int64_t

vector<vector<int>> dp(128, vector<int>(128, 1ll << 61));

void prec() {
  dp[0][0] = 0;
  for (int add = 1; add < 64; ++add) {
    for (int i = 63; i >= 0; --i) {
      for (int j = 63; j >= 0; --j) {
        dp[i][j + add] = min(dp[i][j + add], dp[i][j] + (1ll << add));
        dp[i + add][j] = min(dp[i + add][j], dp[i][j] + (1ll << add));
      }
    }
  }
}

void solve() {
  int X, Y;
  cin >> X >> Y;
  int i = 0, j = 0;
  while (X ^ Y) {
    if (X > Y) {
      X >>= 1;
      ++i;
    } else {
      Y >>= 1;
      ++j;
    }
  }
  int ans = dp[i][j];
  for (int k = 0; k < 3; ++k) {
    for (int l = 0; l < 3; ++l) {
      if ((X >> k) == (Y >> l)) {
        ans = min(ans, dp[i + k][j + l]);
      }
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  prec();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}