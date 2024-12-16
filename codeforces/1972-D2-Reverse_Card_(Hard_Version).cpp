#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
void solve() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for (int i = 1; i <= A; ++i) {
    bool fail = 0;
    for (int j = 1; j <= B && !fail; ++j) {
      if (__gcd(i, j) != 1) continue;
      int b = j * (i + j), a = i * (i + j);
      int add = min(A / a, B / b);
      ans += add;
      fail = !add;
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