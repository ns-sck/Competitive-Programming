#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<int> dp(N, 1);
  for (int j = 0; j < N; ++j) {
    for (int i = 0; i < j; ++i) {
      if (arr[j] > arr[i]) {
        dp[j] = max(dp[j], dp[i] + 1);
      }
    }
  }
  int ans = *max_element(dp.begin(), dp.end());
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