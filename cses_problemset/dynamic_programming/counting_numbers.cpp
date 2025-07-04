#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int A, B, X;
  cin >> A >> B;
  vector<vector<vector<int>>> dp(2, vector<vector<int>>(20, vector<int>(11, -1)));
  auto f = [&](auto&& self, int d, bool t, int s) -> int {
    if (d == -1) {
      return s != 10;
    }
    auto& ref = dp[t][d][s];
    if (~ref) return ref;
    int ans = 0;
    int x = (X / (int) pow(10, d)) % 10;
    int up = t ? x : 9; 
    for (int i = 0; i <= up; ++i) {
      if (i == s) continue;
      ans += self(self, d - 1, t && i == x, (i == 0 && s == 10) ? 10 : i);
    }
    return ref = ans;
  };
  X = B;
  int ans = X > 1 ? f(f, log10(X), 1, 10) : X;
  dp = vector<vector<vector<int>>>(2, vector<vector<int>>(20, vector<int>(11, -1)));
  X = A - 1;
  ans -= X > 1 ? f(f, log10(X), 1, 10) : X;
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