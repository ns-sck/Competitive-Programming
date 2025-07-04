#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;

// https://cses.fi/problemset/task/1636

void solve() {
  int N, X;
  cin >> N >> X;
  vector<int> coins(N);
  for (int& c : coins) cin >> c;
  vector<int> dp(X + 1);
  dp[0] = 1;
  // here the order of the for loops are different
  // we process each coin for the dp array to avoid considering different orderings
  for (int& c : coins) {
    for (int i = 1; i <= X; ++i) {
      if (i >= c) {
        dp[i] = (dp[i] + dp[i - c]) % MOD;
      }
    }
  }
  cout << dp[X] << '\n';
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