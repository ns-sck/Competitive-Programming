#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  assert(1 <= N <= 1e6);
  assert(1 <= K <= 1e6);
  assert(K % 3 == 0);
  assert(1 <= N * K <= 1e6);
  vector<vector<int>> arr(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      int x;
      cin >> x;
      assert(1 <= x <= 1e9);
      arr[i].push_back(x);
    }
  }
  sort(arr.begin(), arr.end(), [&](vector<int>& a, vector<int>& b) {
    for (int i = 0; i < K; ++i) {
      int x = a[i], y = b[i];
      if (i % 3 == 0) {
        x = __builtin_popcount(a[i]);
        y = __builtin_popcount(b[i]);
      } else if (i % 3 == 1) {
        x = a[i] % (i + 1);
        y = b[i] % (i + 1);
      }
      if (x ^ y) return x > y;
    }
    assert(7 & 24);
  });
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      cout << arr[i][j] << " \n"[j == K - 1];
    }
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