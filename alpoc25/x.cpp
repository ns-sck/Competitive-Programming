#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 3e5 + 3;

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
  if (a < b) return 0;
  return fct[a] * fp(fct[b] * fct[a - b] % MOD, MOD - 2) % MOD;
}

void solve() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> adj(N);
  fact();
  for (int i = 1; i < N; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }
  vector<vector<int>> dp(N, vector<int>(N + 1));
  int ans = 0;
  auto dfs = [&](auto&& self, int u) -> void {
    if (!adj[u].size()) {
      for (int i = 0; i <= N; ++i) {
        dp[u][i] = 1;
      }
      return;
    }
    for (int i = 0; i <= N; ++i) {
      dp[u][i] = 1;
    }
    for (int& v : adj[u]) {
      self(self, v);
      for (int i = 1; i <= N; ++i) {
        dp[u][i] += dp[v][i - 1];
      }
    }
    // for (int i = 1; i <= N; ++i) {
    //   dp[u][i] = dp[u][i - 1] + temp[i];
    // }
  };
  dfs(dfs, 0);
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j <= N; ++j) {
      // if (dp[i][j] == dp[i][j - 1]) break;
      int x = (comb(dp[i][j], K) - comb(dp[i][j - 1], K) + MOD) % MOD;
      // if (j > 1 && i > 1) {
      //   int y = (comb(dp[i][j - 1], K) - comb(dp[i][j - 2], K) + MOD) % MOD;
      //   x = (x - y + MOD) % MOD;
      // }
      if (i == 0) {
        x = x * j % MOD;
      } else x = (MOD - x) % MOD;
      ans = (ans + x) % MOD;
    }
  }
  ans *= fp(comb(N, K), MOD - 2);
  ans %= MOD;
  cout << ans << '\n';
  // cout << (900000008ll * 10) % MOD;
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