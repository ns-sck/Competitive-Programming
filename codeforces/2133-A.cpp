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
  vector<bool> a(101);
  bool b = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if (a[x]) b = 1;
    a[x] = 1;
  }
  if (b) cout << "YES\n";
  else cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}