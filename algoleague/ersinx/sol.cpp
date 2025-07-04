#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 998244353;
constexpr int MAX = 1e6 + 1;

int fp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int fct[MAX];

void fact() {
  fct[0] = fct[1] = 1;
  for (int i = 2; i < MAX; ++i) {
    fct[i] = fct[i - 1] * i % MOD;
  }
}

int comb(int a, int b) {
  return fct[a] * fp(fct[b] * fct[a - b] % MOD, MOD - 2) % MOD;
}

void solve() {
  int N;
  cin >> N;
  assert(1 <= N <= 1e6);
  int d = 1, s = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    assert(1 <= x <= 1e6);
    s += x;
    d = d * fct[x] % MOD;
  }
  cout << (fct[s] * fp(d, MOD - 2) % MOD) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  fact();
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}