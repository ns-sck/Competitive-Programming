#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> grid(N + 1, vector<int>(M + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> grid[i][j];
      grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
    }
  }
  int lo = 1, hi = min(N, M), ans = 1ll << 61;
  while (lo <= hi) {
    int mi = (lo + hi) >> 1;
    bool found = 0;
    for (int i = 0; i <= N - mi; ++i) {
      for (int j = 0; j <= M - mi && !found; ++j) {
        int sum = grid[i + mi][j + mi] - grid[i + mi][j] - grid[i][j + mi] + grid[i][j];
        if (sum >= K) {
          found = 1;
        }
      }
    }
    if (found) {
      ans = mi;
      hi = mi - 1;
    } else {
      lo = mi + 1;
    }
  }
  if (ans == 1ll << 61) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
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