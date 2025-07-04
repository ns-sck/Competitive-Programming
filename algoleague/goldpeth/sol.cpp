#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

int fp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}

void solve() {
  int O, P;
  cin >> O >> P;
  assert(0 <= O <= 31);
  if (O == 0) {
    cout << 0 << '\n';
    return;
  }
  vector<vector<array<int, 3>>> dp(O + 1, vector<array<int, 3>>(64));
  for (int j = 0; j < 64; ++j) {
    dp[0][j][0] = 1;
  }
  for (int i = 1; i <= O; ++i) {
    dp[i][2 * i - 2][1] = fp(2, i - 1);
    for (int j = 2 * i - 1; j < 64; ++j) {
      dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1] + dp[i][j - 1][2];
      dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2];
      dp[i][j][2] += dp[i][j - 1][1];
    }
  }
  for (int i = 0; i <= O; ++i) {
    debug(dp[i]);
  }
  int ans = 0, last = -1;
  bool use = 1;
  for (int j = 63; ~j && P && O; --j) {
    if (use) {
      if (dp[O][j][0] < P) {
        ans |= 1ll << j;
        P -= dp[O][j][0];
        debug(ans, P);
        last = j;
        use = 0;
      }
    } else {
      if (dp[O - 1][j][0] < P) {
        ans |= 1ll << j;
        P -= dp[O - 1][j][0];
        O--;
        last = j;
        use = 1;
      }
    }
    if (last >= j + 1) {
      if (!use) O--;
      use = 1;
    }
  }
  cout << ans << '\n';
  // 0001
  // 0010
  // 0011
  // 0100
  // 0110
  // 1000
  // 1100
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