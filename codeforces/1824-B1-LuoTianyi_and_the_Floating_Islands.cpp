#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 2e5 + 2;

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
  int N, K;
  cin >> N >> K;
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (K == 1) {
    cout << 1 << '\n';
    return;
  }
  int ans = 0;
  vector<int> sz(N);
  vector<int> pref(N);
  auto dfs = [&](auto&& self, int u, int p) -> void {
    vector<int> sizes = {1};
    sz[u] = 1;
    for (int& v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      sz[u] += sz[v];
      sizes.push_back(sz[v]);
    }
    if (u) {
      sizes.push_back(N - sz[u]);
    }
    int s = comb(N, K);
    for (int& x : sizes) {
      if (x < K / 2 + 1) continue;
      int a = 0, y = K - x;
      for (int i = K / 2 + 1; i <= min(K, x); ++i) {
        a = (a + comb(x, i) * comb(N - x, K - i)) % MOD;
      }
      s = (s + MOD - a) % MOD;
    }
    ans = (ans + s) % MOD;
  };
  dfs(dfs, 0, -1);
  ans = ans * fp(comb(N, K), MOD - 2) % MOD;
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