#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  int lo = 0, hi = 3e12, ans = lo;
  while (lo <= hi) {
    int mi = (lo + hi) >> 1, c = K, d = 0;
    for (int j = 0; j < N; ++j) {
      c -= max(0ll, mi - arr[j]);
      d += (arr[j] > mi);
    }
    if (c >= 0) {
      ans = mi + (mi - 1) * (N - 1) + d + c;         
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}