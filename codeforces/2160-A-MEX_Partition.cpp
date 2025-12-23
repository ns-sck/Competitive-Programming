#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  vector<int> a(102);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  for (int i = 0; i <= 101; ++i) {
    if (!a[i]) {
      cout << i << '\n';
      return;
    }
  }
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