#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  int last = 0;
  bool one = 0;
  for (int i = 0; i < M; ++i) {
    int x;
    cin >> x;
    if (x <= last) {
      one = 1;
    }
    last = x;
  }
  if (one) {
    cout << 1 << '\n';
  } else {
    cout << N - last + 1 << '\n';
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