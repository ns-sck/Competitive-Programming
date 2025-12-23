#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  vector<int> dpA(N, 1ll << 61);
  vector<vector<int>> dpB(N, vector<int>(M, 1ll << 61));
  dpA[0] = 0;
  for (int i = 0; i < M; ++i) {
    dpB[0][i] = 1;
  }
  for (int i = 1; i < N; ++i) {
    if (a[i] > a[i - 1]) {
      dpA[i] = dpA[i - 1];
    }
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    if (it != b.begin()) {
      dpA[i] = min(dpA[i], dpB[i - 1][it - b.begin() - 1]);
    }
    for (int j = 0; j < M; ++j) {
      if (b[j] > a[i - 1]) {
        dpB[i][j] = min(dpB[i][j], dpA[i - 1] + 1);
      }
      if (j) dpB[i][j] = min(dpB[i][j], dpB[i - 1][j - 1] + 1);
    }
  }
  int ans = min(dpA[N - 1], *min_element(dpB[N - 1].begin(), dpB[N - 1].end()));
  if (ans == 1ll << 61) ans = -1;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}