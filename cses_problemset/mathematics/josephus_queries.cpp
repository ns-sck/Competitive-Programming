#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int Q;
  cin >> Q;
  auto f = [&](auto&& self, int k, int n, int s) -> int {
    int p = (n - s) / 2 + 1;
    if (n == 1) return 1;
    if (n == 2) {
      if (s == 1) return k;
      else return 3 - k;
    }
    if (p >= k) {
      return (k - 1) * 2 + s;
    }
    if (s == 1 && (n & 1)) {
      return 2 * self(self, k - p, n / 2, 2);
    } else if (s == 1) {
      return 2 * self(self, k - p, n / 2, 1);
    } else if (n & 1) {
      return 2 * self(self, k - p, n / 2 + 1, 1) - 1;
    } else {
      return 2 * self(self, k - p, n / 2, 2) - 1;
    }
  };
  while (Q--) {
    int n, k;
    cin >> n >> k;
    cout << f(f, k, n, 2) << '\n';
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