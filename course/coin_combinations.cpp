#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;

void solve() {
  int N, T;
  cin >> N >> T;
  vector<int> coins(N);
  for (int& x : coins) cin >> x;
  vector<int> dp(T + 1);
  dp[0] = 1;
  // dp[i] i'ninci elemana kac kere ulasabildigimizi tutuyor
  for (int& c : coins) {
    for (int i = 1; i <= T; ++i) {
      if (i - c >= 0) {
        dp[i] = (dp[i] + dp[i - c]) % MOD;
      }
    }
  }
  cout << dp[T] << '\n';
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