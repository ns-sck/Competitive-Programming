#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  // n^2 soln.
  int N, M;
  cin >> N >> M;
  assert(1 <= N <= 1e5);
  assert(1 <= M <= 1e5);
  vector<int> a(N), b(M);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    assert(1 <= a[i] <= 1e9);
  }
  for (int i = 0; i < M; ++i) {
    cin >> b[i];
    assert(1 <= b[i] <= 1e9);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < M; ++i) {
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
      if (a[j] >= b[i]) break;
      cnt++;
    }
    cout << cnt << " \n"[i == M - 1];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}