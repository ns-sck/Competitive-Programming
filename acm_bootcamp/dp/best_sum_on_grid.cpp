#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  // N <= 20
  int N;
  cin >> N;
  vector<vector<int>> grid(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }
  // 2 ^ N states
  vector<int> dp(1 << N);
  // iterate over all subsets like 11001, 01001 etc.
  // if we are in state 01010, this means that we pick elements
  // from second and fourth columns, so we can not pick elements
  // from these columns again, but with considering other 3 columns
  // we can give information to 11010, 01110 and 01011
  // on the other hand, 10010 will also give information to 11010
  // after each number give information to bigger numbers
  // we will have the answer in 11111: we get elements from all columns
  for (int i = 1; i < (1 << N); ++i) {
    int row = __builtin_popcount(i);
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) {
        dp[i] = max(dp[i], dp[i & ~(1 << j)] + grid[row - 1][j]);
      }
    }
  }
  cout << dp[(1 << N) - 1] << '\n';
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