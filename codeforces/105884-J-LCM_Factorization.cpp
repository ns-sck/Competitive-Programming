#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 3e5 + 3;
constexpr int MOD = 998244353;
vector<int> spf(MAX);
vector<int> prs;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      prs.push_back(i);
    }
    for (int j = 0; i * prs[j] < MAX; ++j) {
      spf[i * prs[j]] = prs[j];
      if (prs[j] == spf[i]) {
        break;
      }
    }
  }
}

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
  if (a < b) {
    return 0;
  }
  return fct[a] * fp(fct[b] * fct[a - b] % MOD, MOD - 2) % MOD;
}

void solve() {
  int N, K;
  cin >> N >> K;
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    while (x > 1) {
      int y = spf[x];
      mp[y]++;
      while (x % y == 0) {
        x /= y;
      }
    }
  }
  int ans = 0;
  for (auto [x, y] : mp) {
    debug(x, y);
    int cnt = (comb(N, K) - comb(N - y, K) + MOD) % MOD;
    ans += cnt * x;
    ans %= MOD;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  sieve();
  fact();
  while (t--) {
    solve();
  }
  return 0;
}