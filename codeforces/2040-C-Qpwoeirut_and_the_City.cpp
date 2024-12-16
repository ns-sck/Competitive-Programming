#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  int ans = 0;
  if (N & 1) {
    int a = 0;
    for (int i = 1; i < N - 1; i += 2) {
      int z = max(arr[i + 1], arr[i - 1]);
      if (z >= arr[i]) ans += z - arr[i] + 1;
    }
  } else {
    vector<pair<int, int>> vals;
    for (int i = 1; i < N - 1; i += 2) {
      int z = max(arr[i - 1], arr[i + 1]);
      int x = max(0ll, z - arr[i] + 1);
      z = max(arr[i], arr[i + 2]);
      int y = max(0ll, z - arr[i + 1] + 1);
      vals.emplace_back(x, y);
    }
    vector<vector<int>> dp(vals.size(), vector<int>(2));
    dp[0][0] = vals[0].first;
    dp[0][1] = vals[0].second;
    for (int i = 1; i < vals.size(); ++i) {
      dp[i][0] = dp[i - 1][0] + vals[i].first;
      dp[i][1] = min(dp[i - 1][0] + vals[i].second, dp[i - 1][1] + vals[i].second);
    }
    ans = min(dp[vals.size() - 1][0], dp[vals.size() - 1][1]);
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