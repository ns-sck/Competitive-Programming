#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int A, B;
  cin >> A >> B;
  int ans = A;
  for (int i = 2; i <= B; ++i) {
    ans += (A + i) / (i * i);
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