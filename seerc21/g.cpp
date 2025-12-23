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
  N <<= 1;
  vector<array<int, 2>> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i][0] >> a[i][1];
  }
  sort(a.begin(), a.end());
  set<array<int, 2>> rights;
  for (int i = 0; i < N; ++i) {
    if (a[])
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