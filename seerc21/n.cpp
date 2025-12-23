#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  vector<int> b(n + 1);

  for (int i = 0; i < n + 1; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n + 1; ++i) {
    cin >> b[i];
  }

  int ans = 0;

  for (int i = n; i >= 1; --i) {
    b[i] -= min(b[i], a[i]);
    int add = (b[i] + 1) / 2;
    b[i - 1] = b[i - 1] + add;
    ans += add; 
  }
  b[0] -= a[0];
  debug(ans);
  if (b[0] > 0) {
    cout << "-1\n";
  }
  else {
    cout << ans << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}