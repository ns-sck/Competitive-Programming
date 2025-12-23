#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 1e5 + 1;

void solve() {
  // no set soln
  int N;
  cin >> N;
  assert(1 <= N <= 1e3);
  vector<int> arr(N);
  vector<bool> seen(MAX);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    assert(1 <= arr[i] <= 1e5);
    seen[arr[i]] = 1;
  }
  int sum = 0, cnt = 0;
  for (int i = 0; i < MAX; ++i) {
    if (seen[i]) {
      sum += i;
      cnt += 1;
    }
  }
  cout << sum / cnt << '\n';
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