#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;
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
  string S;
  cin >> N >> S;
  int k = 0;
  if (N & 1) {
    cout << 0 << '\n';
    return;
  }
  N >>= 1;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '(') {
      ++k;
    } else {
      --k;
      N--;
    }
    if (k < 0) {
      cout << 0 << '\n';
      return;
    }
  }
  N -= k;
  cout << (comb(2 * N + k, N) * (1 + k) % MOD) * fp(N + k + 1, MOD - 2) % MOD << '\n';
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