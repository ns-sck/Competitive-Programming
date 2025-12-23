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
  int best = 0, s = 0;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    if (i) s += abs(a[i] - a[i - 1]);
  }
  best = max(abs(a[0] - a[1]), abs(a[N - 1] - a[N - 2]));
  for (int i = 1; i < N - 1; ++i) {
    int d1 = abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]);
    int d2 = abs(a[i - 1] - a[i + 1]);
    best = max(best, d1 - d2);
  }
  cout << s - best << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}