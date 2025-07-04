#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  auto f = [&](int x) {
    cout << "F " << x << '\n';
    cout.flush();
    int y;
    cin >> y;
    return y;
  };
  auto s = [&](int x) {
    cout << "S " << x << '\n';
    cout.flush();
    int y;
    cin >> y;
    return y;
  };
  int lo = 1, hi = K, ans = 1;
  while (lo <= hi) {
    int mi = (lo + hi) >> 1;
    int x = f(mi);
    int y = s(K - mi + 1);
    debug(lo, hi);
    if (x > y) {
      ans = mi;
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  if (K & 1) {
    cout << "! " << f(ans) << '\n';
  } else {
    cout << "! " << s(K - ans + 1) << '\n';
  }
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}