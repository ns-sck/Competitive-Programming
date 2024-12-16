#include <bits/stdc++.h>
using namespace std;

#define int int64_t
int ans, arr[21];

void solve() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i < (1 << K); ++i) {
    int mult = 1;
    for (int j = 0; j < K; ++j) {
      if (~(i >> j) & 1) continue;
      int x = arr[j];
      if (mult > N / x) {
        mult = N + 1;
        break;
      } 
      mult *= x;
    }
    if (__builtin_popcount(i) & 1) {
      ans += N / mult;
    } else {
      ans -= N / mult;
    }
  }
  cout << ans << '\n';
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