#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 5e6 + 1;
constexpr int MOD = 1e9 + 7;

void solve() {
  int Q;
  cin >> Q;
  assert(1 <= Q <= 2e5);
  vector<array<int, 2>> dp(MAX, {-1, -1}), pref(MAX);
  auto f = [&](auto&& self, int x) -> array<int, 2> {
    if (~dp[x][0]) {
      return dp[x];
    }
    if (__builtin_popcountll(x) == 1) {
      return dp[x] = {2 * dp[x / 2][0], 2 * dp[x / 2][1]};
    }
    int mod = x % (1ll << (63 - __builtin_clzll(x)));
    if (mod == 1) {
      return dp[x] = {1, x - 2};
    }
    auto y = self(self, mod);
    return dp[x] = {2 * y[0], 2 * y[1]};
  };   
  dp[2] = pref[2] = {1, 0};
  for (int i = 3; i < MAX; ++i) {
    f(f, i);
    pref[i][0] = (pref[i - 1][0] + dp[i][0]) % MOD;
    pref[i][1] = (pref[i - 1][1] + dp[i][1]) % MOD;
  }
  debug(sizeof(dp));
  while (Q--) {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    assert(1 <= a <= 1e9);
    assert(1 <= b <= 1e9);
    assert(1 <= l <= r < MAX);
    int x = (pref[r][0] - pref[l - 1][0] + MOD) % MOD;
    int y = (pref[r][1] - pref[l - 1][1] + MOD) % MOD;
    int ans = (((a + b) * x % MOD) + ((a ^ b) * y % MOD)) % MOD;
    cout << ans << '\n';
  }
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