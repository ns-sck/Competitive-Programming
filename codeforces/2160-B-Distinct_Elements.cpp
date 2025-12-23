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
  vector<int> arr(N), ans(N);
  int cnt = 1;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    if (!i) {
      ans[i] = cnt++;
    } else {
      int diff = arr[i] - arr[i - 1];
      if (diff > i) {
        ans[i] = cnt++;
      } else {
        ans[i] = ans[i - diff];
      }
    }
    cout << ans[i] << " \n"[i == N - 1];
  }
}
// 1 3 6
// 1 2 3

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