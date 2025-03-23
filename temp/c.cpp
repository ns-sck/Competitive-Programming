#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int X, Y;
  cin >> X >> Y;
  if (X == Y) {
    cout << -1 << '\n';
    return;
  }
  if (X + Y == (X ^ Y)) {
    cout << 0 << '\n';
    return;
  }
  if (X < Y) swap(X, Y);
  int i = 64 - __builtin_clzll(X);
  int get = 1ll << i;
  int k = get - X;
  cout << k << '\n';
  X += k, Y += k;
  assert(X + Y == (X ^ Y));
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