#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MOD = 1e9 + 7;
constexpr int inv2 = 500000004;

void solve() {
  int N;
  cin >> N;
  int ans = 0;
  int sq = sqrt(N) + 1;
  int lb = sq * (sq - 1) % MOD * inv2 % MOD;
  auto gauss = [&](int b) {
    return b * (b + 1) % MOD * inv2 % MOD - lb;
  };
  for (int i = 1; i * i <= N; ++i) {
    ans = (ans + i * (N / i)) % MOD;
    int up = N / i;
    ans = (ans + gauss(up % MOD) % MOD) % MOD;
  }
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