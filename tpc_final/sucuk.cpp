#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 2500 + 1;

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
int inv[MAX];

void fact() {
  fct[0] = fct[1] = 1;
  inv[0] = inv[1] = 1;
  for (int i = 2; i < MAX; ++i) {
    fct[i] = fct[i - 1] * i % MOD;
    inv[i] = fp(fct[i], MOD - 2);
  }
}

int comb(int a, int b) {
  return fct[a] * fp(fct[b] * fct[a - b] % MOD, MOD - 2) % MOD;
}

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  vector<vector<int>> dp(N, vector<int>(MAX, 0));
  dp[0][0] = dp[0][1] = 1;
  for (int i = 2; i <= arr[0]; ++i) {
    dp[0][i] = comb(arr[0] - 1, i - 1);
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= arr[i]; ++j) {
      for (int k = i; k <= MAX - j - 1; ++k) {
        dp[i][j + k] = (dp[i][j + k] + ((((fct[k + j] * inv[j] % MOD) * inv[k] % MOD) * comb(arr[i] - 1, j - 1) % MOD) * dp[i - 1][k]) % MOD) % MOD;
      }
    }
  }
  vector<int> pref(MAX + 1);
  for (int i = 1; i <= MAX - 1; ++i) {
    pref[i] = (pref[i - 1] + dp[N - 1][i]) % MOD;
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    cout << (pref[r] - pref[l - 1] + MOD) % MOD << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fact();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}