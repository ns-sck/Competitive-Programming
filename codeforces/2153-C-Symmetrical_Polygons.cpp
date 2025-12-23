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
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    mp[x]++;
  }
  int a = 0, b = 0, sum = 0, ans = 0;
  for (auto [x, y] : mp) {
    if (y == 1) {
      if (a + sum > x) {
        ans = a + sum + x;
      }
      b = a, a = x;
    } else if (y & 1) {
      b = a, a = x;
      sum += (y - 1) * x;
      ans = a + b + sum;
    } else {
      if (sum || a || (y > 2)) {
        ans = a + b + sum + x * y;
      }
      sum += x * y;
    }
  }
  cout << ans << '\n';
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