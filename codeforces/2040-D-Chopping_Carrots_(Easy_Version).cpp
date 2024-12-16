#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N), a, b;
  int mn = 3001, mx = 0;
  for (int& x : arr) cin >> x;
  sort(arr.begin(), arr.end());
  for (int& x : arr) {
    a.emplace_back(x / K);
    b.emplace_back(x);
    mn = min(mn, x);
  }
  int ans = 1ll << 61;
  for (int i = 1; i <= 3000; ++i) {
    bool ok = 1;
    int mx = 0;
    for (int j = 0; j < N; ++j) {
      if (b[j] < i) {
        ok = 0;
        break;
      }
      int lo = 1, hi = K;
      int w = 0;
      while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        int x = arr[j] / mi;
        if (x < i) {
          hi = mi - 1;
        } else {
          w = x;
          lo = mi + 1;
        }
      }
      mx = max(mx, w);
    }
    if (!ok) continue;
    ans = min(ans, mx - i);
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