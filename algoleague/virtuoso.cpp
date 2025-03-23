#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 444444444;

void solve() {
  int N;
  cin >> N;
  assert(1 <= N <= 4444);
  vector<int> arr(N);
  for (int& x : arr) {
    cin >> x;
    assert(1 <= x <= 445);
  }
  auto ok = [&](int a, int b) {
    return a == b || a * 26 <= b * 25;
  };
  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(446, vector<int>(446)));
  // number of subsequences for array 1,...,i, with last element j and having k difference at last
  dp[0][0][0] = 1;
  int ans = - N;
  for (int i = 1; i <= N; ++i) {
    dp[i][arr[i - 1]][0] = 1;
    for (int j = 1; j <= 445; ++j) {
      int diff = arr[i - 1] - j;
      for (int k = 0; k <= 445; ++k) {
        dp[i][j][k] += dp[i - 1][j][k];
        if (ok(k, diff)) {
          dp[i][arr[i - 1]][diff] = (dp[i][arr[i - 1]][diff] + dp[i - 1][j][k]) % MOD;
        }
        if (i == N) {
          ans = (ans + dp[i][j][k]) % MOD;
        }
      }
    }
  }
  // int ans2 = 0;
  // auto dfs = [&](auto&& self, vector<int> path, int i, int diff) {
  //   if (i == N) {
  //     if (path.size() <= 1) return;
  //     for (int j = 0; j < path.size(); ++j) {
  //       cout << path[j] << ' ';
  //     }
  //     cout << '\n';
  //     ans2++;
  //     return;
  //   }
  //   self(self, path, i + 1, diff);
  //   if (path.empty() || ok(diff, arr[i] - path.back())) {
  //     path.emplace_back(arr[i]);
  //     self(self, path, i + 1, path.size() == 1 ? 0 : arr[i] - path[path.size() - 2]);
  //     path.pop_back();
  //   }
  // };
  // dfs(dfs, {}, 0, 0);
  // cout << ans2 << '\n';
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}