#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M, P;
  string S;
  cin >> N >> M >> P >> S;
  assert(1 <= N <= 2e5);
  assert(1 <= M <= 100);
  assert(1 <= P <= 1e6);
  for (int i = 2; i * i <= P; ++i) {
    assert(P % i);
  }
  vector<int> dp(N);
  vector<int> last(10, -1);
  int least = -1;
  int x = 10;
  for (int i = 0; i < N; ++i) {
    if ((x - 1) % P == 0) {
      least = i + 1;
      break;
    }
    x = x * 10 % P;
  }
  if (P > 7) {
    debug(least);
    for (int i = 0; i < N; ++i) {
      int d = S[i] - '0';
      assert(0 <= d <= 9);
      if (~last[d]) dp[i] = dp[last[d]] + 1;
      if (~least && i >= least) {
        dp[i] = max(dp[i], dp[i - least] + (S[i] == S[i - least] ? 1 : M));
      }
      last[d] = i;
    }
  } else {
    for (int i = 0; i < N - ((P & 3) != 3); ++i) {
      int d = S[i] - '0';
      assert(0 <= d <= 9);
      debug(i, dp, i - least);
      if (P == 7) {
        if (~last[d]) dp[i] = dp[last[d]] + 1;
        if (~least && i >= least) dp[i] = max(dp[i], dp[i - least] + (S[i] == S[i - least] ? 1 : M));
        if (d == 0 && ~last[7]) dp[i] = max(dp[i], dp[last[7]] + M);
        if (d == 1 && ~last[8]) dp[i] = max(dp[i], dp[last[8]] + M);
        if (d == 2 && ~last[9]) dp[i] = max(dp[i], dp[last[9]] + M);
        if (d == 7 && ~last[0]) dp[i] = max(dp[i], dp[last[0]] + M);
        if (d == 8 && ~last[1]) dp[i] = max(dp[i], dp[last[1]] + M);
        if (d == 9 && ~last[2]) dp[i] = max(dp[i], dp[last[2]] + M);
      } else {
        for (int j = 0; j < 10; ++j) {
          if (~last[j]) dp[i] = max(dp[i], dp[last[j]] + (j == d ? 1 : M));
        }
      }
      last[d] = i;
    }
  }
  cout << *max_element(dp.begin(), dp.end());
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