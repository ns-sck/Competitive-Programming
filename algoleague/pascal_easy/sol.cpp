#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;

void solve() {
  int N, A, B;
  cin >> N >> A >> B;
  assert(2 <= N <= 1e9);
  assert(1 <= A <= 1e9);
  assert(1 <= B <= 1e9);
  auto f = [&](auto&& self, int x) -> int {
    if (x == 2) return (A + B) % MOD;
    if (__builtin_popcount(x) == 1) {
      return (self(self, x / 2) * 2) % MOD;  
    }
    int mod = x % (1ll << (63 - __builtin_clzll(x)));
    if (mod == 1) {
      return ((x - 2) * (A ^ B) + A + B) % MOD;
    }
    return (2 * self(self, mod)) % MOD;
  };
  cout << f(f, N) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  assert(1 <= t <= 2e5);
  while (t--) {
    solve();
  }
  return 0;
}