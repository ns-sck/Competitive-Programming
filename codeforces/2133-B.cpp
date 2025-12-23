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
  vector<int> a(N);
  int ans = 0;
  for (int& x : a) cin >> x;
  sort(a.begin(), a.end());
  for (int i = N - 1; i >= 0; --i) {
    if ((i & 1) == (N & 1)) {
      ans += max(a[i], a[i + 1]);
    }
  }
  if (N & 1) ans += a[0];
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}