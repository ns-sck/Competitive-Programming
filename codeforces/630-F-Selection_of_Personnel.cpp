#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  auto get = [&](int x) {
    int num = 1, denom = 1;
    for (int i = 1; i <= x; ++i) {
      num *= N - i + 1;
      denom *= i;
      if (num % denom == 0) {
        num /= denom;
        denom = 1;
      }
    }
    return num / denom;
  };
  int ans = get(7) + get(6) + get(5);
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