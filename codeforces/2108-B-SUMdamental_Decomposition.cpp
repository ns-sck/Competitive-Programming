#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, X;
  cin >> N >> X;
  if (N == 1 && !X) {
    cout << -1 << '\n';
    return;
  }
  int ans;
  int c = __builtin_popcountll(X);
  if (X <= 1 && (N & 1) ^ (X & 1)) {
    ans = 6 + N - 3;
  } else if (c > N) {
    ans = X;
  } else {
    if (X & 1) {
      c--, N--, X--;
      ans = 1 + N - c + X + ((N - c) & 1);
    } else {
      ans = N - c + X + ((N - c) & 1);
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