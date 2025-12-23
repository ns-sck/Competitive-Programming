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
  vector<int> arr(2 * N);
  for (int& x : arr) {
    cin >> x;
  }
  vector<vector<int>> dp(50 + 1, vector<int>(50 + 1, -1));
  auto dfs = [&](int i, int a, int b) -> int {
    if (i == 2 * N) {
      if (a == b) {
        return 0;
      } else {
        return 1ll << 61;
      }
    }
    auto& ref = dp[a][b];
    if (~ref) {
      return ref;
    }
    int j = a + 1;
    if (j <= b) {
      
    }
  };
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}