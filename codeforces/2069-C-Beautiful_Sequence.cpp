#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MOD = 998244353;

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  int one = 0;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    one += arr[i] == 1;
  }
  vector<int> dp(N + 1);
  int ans = 0, three = 0, c = 0;
  for (int i = N - 1; ~i; --i) {
    dp[i] = dp[i + 1];
    if (arr[i] == 1) {
      --one;
      // c = 0;
    } else if (arr[i] == 2) {
      dp[i] *= 2;
      dp[i] += c;
      dp[i] %= MOD;
      ans += dp[i] * one;
      ans %= MOD;
      c = 0;
    } else {
      ++c;
      ++three;
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}