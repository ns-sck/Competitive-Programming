#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

// #define int int64_t
constexpr int MOD = 1e9 + 7;
int dp[201][201][1001];

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  sort(arr.begin(), arr.end());
  auto add = [&](int& a, int b) {
    a = (long long) (a + b) % MOD;
  };
  dp[0][0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < i; ++j) {
      int diff = i > 1 ? arr[i - 1] - arr[i - 2] : 0;
      for (int k = 0; k <= K; ++k) {
        int val = (long long) (k + j * diff) % MOD;
        if (val > K) continue;
        int x = dp[i - 1][j][k];
        add(dp[i][j][val], x);
        add(dp[i][j][val], (long long) j * x % MOD);
        add(dp[i][j + 1][val], x);
        if (j) add(dp[i][j - 1][val], (long long) j * x % MOD);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= K; ++i) {
    add(ans, dp[N][0][i]);
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