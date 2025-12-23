#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

constexpr int MOD = 1e9 + 7;

void solve() {
  int N, L;
  cin >> N >> L;
  vector<int> arr(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  vector<vector<int>> dp(N + 1, vector<int>(L + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    int k = i;
    if (k > 104) {
      k = 104;
    }
    for (; k >= 1; --k) {
      // vector<vector<int>> modpref(N);
      // _ _ _ _ _ _ _
      vector<int> modpref(i);
      for (int j = 0; j <= L; ++j) {
        if (j < i) {
          modpref[j] = dp[k - 1][j];
          continue;
        }
        int div = j / i - 1;
        if (j - (arr[i] + 1) * i >= 0) {
          modpref[j % i] = (modpref[j % i] + MOD - dp[k - 1][j - (arr[i] + 1) * i]) % MOD;
        }
        dp[k][j] = (dp[k][j] + modpref[j % i]) % MOD;
        modpref[j % i] = (modpref[j % i] + dp[k - 1][j]) % MOD;
      }
    }
    debug(dp);
  }
  for (int i = 1; i <= N; ++i) {
    cout << dp[i][L] << " ";
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