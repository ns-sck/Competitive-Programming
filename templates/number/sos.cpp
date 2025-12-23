#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  // an array with 2^N elements
  // calculate f(x) for each x in [1, 2^N]
  // where f(x) = ∑ A[i] where i ⊆ x
  // 3^N solution:
  vector<int> f(1 << N);
  vector<int> a(1 << N);
  for (int mask = 0; mask < (1 << N); ++mask) {
    f[mask] = a[0]; 
    for (int i = mask; i > 0; i = (i - 1) & mask) {
      f[mask] += a[i];
    }
  }
  // define S(mask, i) 
  // S(1011010, 3) = {1010000, 1010010, 1011000, 1011010} -> first 3 bits differ (0 based)
  // if i'th bit of a mask is 0 -> S(mask, i) = S(mask, i - 1)
  // if i'th bit of a mask is 1 -> S(mask, i) = S(mask, i - 1) U S(mask ^ (1 << i), i - 1)
  vector<vector<int>> dp(1 << N, vector<int>(N + 1));
  for (int mask = 0; mask < (1 << N); ++mask) {
    dp[mask][0] = a[mask];
    for (int i = 0; i < N; ++i) {
      dp[mask][i + 1] = dp[mask][i];
      if ((mask >> i) & 1) {
        dp[mask][i + 1] += dp[mask ^ (1 << i)][i];
      }
    }
    f[mask] = dp[mask][N];
  }
  // memory optimized
  f = a;
  for (int i = 0; i < N; ++i) {
    for (int mask = 0; mask < (1 << N); ++mask) {
      if ((mask >> i) & 1) {
        f[mask] += f[mask ^ (1 << i)];
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}