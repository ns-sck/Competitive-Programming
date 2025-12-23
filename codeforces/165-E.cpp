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
  vector<int> f(1 << 22);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    f[a[i]] = a[i];
  }
  int n = f.size();
  for (int i = 0; i < log2(n); ++i) {
    for (int j = 0; j < n; ++j) {
      if ((j >> i) & 1) {
        f[j] = max(f[j ^ (1 << i)], f[j]);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    int x = 0;
    for (int j = 0; j < 22; ++j) {
      if (~(a[i] >> j) & 1) x |= 1 << j;
    }
    if (f[x]) {
      cout << f[x] << ' ';
    } else {
      cout << -1 << ' ';
    }
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