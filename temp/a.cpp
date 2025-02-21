#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  for (int i = 0; i < N; ++i) {
    bool ok = 1;
    for (int j = i - 1; j >= i - X && ok; --j) {
      if (j < 0) break;
      ok &= arr[j] > arr[i];
    }
    for (int j = i + 1; j <= i + Y && ok; ++j) {
      if (j >= N) break;
      ok &= arr[j] > arr[i];
    }
    if (ok) {
      cout << i + 1 << '\n';
      return;
    }
  }
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}