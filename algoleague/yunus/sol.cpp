#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> h(N), a(N), s(N);
  for (int& x : h) cin >> x;
  for (int& x : a) cin >> x;
  for (int& x : s) cin >> x;
  int lo = 0, hi = X, ans = 0;
  auto f = [&](int l, int cnt, int sc) -> int {
    return cnt * l + cnt * (cnt - 1) / 2 * sc;
  };
  while (lo <= hi) {
    int mi = (lo + hi) >> 1;
    int x = X, c = 0, lc = 0;
    for (int i = 0; i < N; ++i) {
      if (mi < a[i]) continue;
      int cnt = min((mi - a[i]) / s[i] + 1, (h[i] + Y - 1) / Y);
      c += cnt;
      x -= f(a[i], cnt, s[i]);
      if (a[i] + (cnt - 1) * s[i] == mi) ++lc;
      if (x < -(1ll << 51)) break;
    }
    if (x <= 0 && lc * mi + x > 0) {
      c -= (mi - x) / mi;
      x = 1;
    }
    if (x > 0) {
      ans = max(ans, c);
      lo = mi + 1;
    } else {
      hi = mi - 1;
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