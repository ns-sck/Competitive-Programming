#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 998244353;

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> arr(32, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j <= 30; ++j) {
      arr[j][i] = (x >> j) & 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < 31; ++i) {
    int z = 1, zs = 0, o = 0, os = 0, x = 0;
    for (int j = 0; j < N; ++j) {
      if (x ^= arr[i][j]) {
        ans = (ans + ((z * (j + 1) - zs + MOD) % MOD) * (1 << i)) % MOD;
        o++;
        os = (os + j + 1) % MOD;
      } else {
        ans = (ans + ((o * (j + 1) - os + MOD) % MOD) * (1 << i)) % MOD;
        z++;
        zs = (zs + j + 1) % MOD;
      }
    } 
  }
  cout << ans << '\n';
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