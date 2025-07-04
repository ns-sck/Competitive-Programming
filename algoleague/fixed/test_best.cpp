#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int size[3];
  ofstream o("best.txt");
  o << 10000 << ' ' << 2 << '\n';
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int worst = 9699690 * 100;
  for (int i = 0; i < 10000; ++i) {
    int x = rng() % 999999999 + 1;
    int y = rng() % 2;
    if (y == 0) x = worst;
    o << x << ' ';
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