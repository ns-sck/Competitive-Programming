#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  vector<int> a(5);
  for (int i = 0; i < 5; ++i) {
    if (i == 2) continue;
    cin >> a[i];
  }
  int ans = 1;
  auto calc = [&](vector<int>& v) -> int {
    int c = 0;
    for (int i = 0; i < 3; ++i) {
      if (a[i] + a[i + 1] == a[i + 2]) ++c;
    }
    return c;
  };
  a[2] = a[0] + a[1];
  ans = max(ans, calc(a));
  a[2] = a[3] - a[1];
  ans = max(ans, calc(a));
  a[2] = a[4] - a[3];
  ans = max(ans, calc(a));
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