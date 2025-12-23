#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> basis(31);
  auto insert = [&](int x) {
    for (int i = 30; i >= 0; --i) {
      if ((x >> i) & 1) {
        if (!basis[i]) {
          basis[i] = x;
          return true;
        } else {
          x ^= basis[i];
        }
      }
    }
    return false;
  };
  auto check = [&](int x) {
    for (int i = 20; i >= 0; --i) {
      if ((x >> i) & 1) {
        if (!basis[i]) {
          return false;
        }
        x ^= basis[i];
      }
    }
    return true;
  };
  int ans = 0, seg = 0, xr = 0;
  for (int i = 0, x; i < N; ++i) {
    cin >> x;
    seg ^= x;
    xr ^= x;
    if (insert(seg)) {
      ++ans;
      seg = 0;
    }
  }
  if (xr == 0) ans = -1;
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