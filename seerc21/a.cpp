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
  string A, B;
  cin >> A >> B;
  int s = 0, d = 0, ans = 0;
  vector<int> diff;
  vector<int> lrg;
  for (int i = 0; i < N; ++i) {
    if (A[i] < B[i]) {
      diff.push_back(i);
      ans += N - i;
    } else if (A[i] > B[i]) {
      lrg.push_back(i);
    }
  }
  debug(ans);
  for (int i = 0; i < N; ++i) {
    if (A[i] == B[i]) {
      auto j = lower_bound(diff.begin(), diff.end(), i);
      if (j != diff.end()) {
        auto k = lower_bound(lrg.begin(), lrg.end(), i);
        if (k == lrg.end() || *k > *j) {
          ans += N - *j;
        }
      }
    }
    debug(i, ans);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}