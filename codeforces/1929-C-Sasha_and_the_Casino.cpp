#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int K, X, A;
  cin >> K >> X >> A;
  --A;
  --K;
  int lost = 1;
  for (int i = 1; i < X + 1; ++i) {
    int need = ((lost + 1) + K - 1) / K;
    if (need + lost > A + 1) {
      cout << "NO\n";
      return;
    }
    lost += need;
  }
  cout << "YES\n";
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