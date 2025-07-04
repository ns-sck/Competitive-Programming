#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  vector<vector<int>> grid(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;
  vector<array<int, 2>> dp(N, {1ll << 57, 1ll << 57});
  dp[0][0] = 0, dp[0][1] = a[0];
  for (int i = 1; i < N; ++i) {
    bool x = 0, y = 0, z = 0;
    for (int j = 0; j < N; ++j) {
      if (grid[i][j] == grid[i - 1][j]) x = 1;
      if (grid[i][j] == grid[i - 1][j] + 1) y = 1;
      if (grid[i][j] == grid[i - 1][j] - 1) z = 1;
    }
    // ayni durum yok, ikimiz de kullanabiliriz/kullanmayabiliriz
    if (!x) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1] + a[i];
    }
    // benden onceki kullandiginda sorun oluyor, eger bu yoksa onun kullanmayip benim kullandigim durumu sayabiliriz
    if (!y) {
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    }
    // onceki kullanmayip ben kullanirsam sorun oluyor, eger bu yoksa bu durumu da kullanabiliriz
    if (!z) {
      dp[i][1] = min(dp[i][1], a[i] + dp[i - 1][0]);
    }
  }
  int ans = min(dp[N - 1][0], dp[N - 1][1]);
  dp = vector<array<int, 2>>(N, {1ll << 57, 1ll << 57});
  dp[0][0] = 0, dp[0][1] = b[0];
  for (int j = 1; j < N; ++j) {
    bool x = 0, y = 0, z = 0;
    for (int i = 0; i < N; ++i) {
      if (grid[i][j] == grid[i][j - 1]) x = 1;
      if (grid[i][j] == grid[i][j - 1] + 1) y = 1;
      if (grid[i][j] == grid[i][j - 1] - 1) z = 1;
    }
    if (!x) {
      dp[j][0] = dp[j - 1][0];
      dp[j][1] = dp[j - 1][1] + b[j];
    }
    if (!y) {
      dp[j][0] = min(dp[j][0], dp[j - 1][1]);
    }
    if (!z) {
      dp[j][1] = min(dp[j][1], b[j] + dp[j - 1][0]);
    }
  }
  ans += min(dp[N - 1][0], dp[N - 1][1]);
  if (ans >= 1e13) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
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