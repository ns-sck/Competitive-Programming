#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 2002;

int fp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int fct[MAX];

void fact() {
  fct[0] = fct[1] = 1;
  for (int i = 2; i < MAX; ++i) {
    fct[i] = fct[i - 1] * i % MOD;
  }
}

int comb(int a, int b) {
  return fct[a] * fp(fct[b] * fct[a - b] % MOD, MOD - 2) % MOD;
}

void solve() {
  int N, H;
  cin >> N >> H;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  vector<vector<int>> dp(N, vector<int>(H + 2));
  // dp[i][j] number of ways having j open segments on index i
  dp[0][0] = dp[0][H - arr[0]] = 1;
  for (int i = 1; i < N; ++i) {
    int j = H - arr[i];
    dp[i][j] = dp[i - 1][j];
    dp[i][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
    if (j) {
      dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] % MOD);
      dp[i][j - 1] = dp[i - 1][j];
    }
  }
  cout << dp[N - 1][H - arr[N - 1]] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fact();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}