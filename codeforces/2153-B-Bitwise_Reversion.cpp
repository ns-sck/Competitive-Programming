#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  vector<int> a(32);
  for (int i = 0; i < 3; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < 31; ++j) {
      if ((x >> j) & 1) {
        a[j]++;
      }
    }
  }
  for (int i = 0; i < 31; ++i) {
    if (a[i] && (~a[i] & 1)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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