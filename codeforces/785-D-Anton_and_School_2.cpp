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
  string S;
  cin >> S;
  int opn = 0, cls = count(S.begin(), S.end(), ')');
  int ans = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '(') {
      opn++;
    } else {
      // N = opn, M = cls
      cls--;
      ans = (ans + comb(opn + cls, opn >= cls ? cls + 1 : opn - 1)) % MOD;
    }
  }
  cout << ans << '\n';
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