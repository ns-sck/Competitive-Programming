#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  double H, L;
  cin >> H >> L;
  double ans = (L * L) - (H * H);
  ans /= 2 * H;
  cout << fixed << setprecision(12) << ans << '\n';
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