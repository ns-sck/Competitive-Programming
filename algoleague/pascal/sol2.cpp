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
  auto f = [&](auto&& self, int x) -> int {
    if (x == 1) return 0;
    if (__builtin_popcount(x) == 1) {
      return __builtin_ctzll(x) & 1;
    }
    int md = x % (1ll << (63 - __builtin_clzll(x)));
    return 1 - self(self, md);
  };
  cout << f(f, N + 1) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}