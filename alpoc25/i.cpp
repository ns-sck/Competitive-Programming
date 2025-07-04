#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 5e5 + 5;

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
  fact();
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }
  vector<int> d(N);
  auto dfs = [&](auto&& self, int u) -> void {
    for (int& v : adj[u]) {
      d[v] = d[u] + 1;
      self(self, v);
      adj[v].push_back(u);
    }
  };
  dfs(dfs, 0);
  int ans = 0;
  auto f = [&](auto&& self, int i) -> void {
    vector<bool> bad(N);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    pq.push({d[i], i});
    set<pair<int, int>> seen;
    vector<bool> see(N);
    vector<int> when(N);
    int j = 0;
    while (pq.size()) {
      auto [dep, u] = pq.top();
      pq.pop();
      see[u] = j++;
      while (seen.size() && d[u] > seen.begin()->first) {
        auto [dep2, v] = *seen.begin();
        int y = comb(j - 1, K - 2) * abs(d[v] - d[i]) % MOD;
        ans += y;
        ans %= MOD;
        seen.erase(seen.begin());
      }
      if (u ^ i) seen.insert({d[u], u});
      for (int& v : adj[u]) {
        if (!see[v] && d[v] > d[i]) {
          pq.push({d[v], v});
        }
      }
    }
    for (auto [aa, bb] : seen) {
      int y = comb(j - 1, K - 2) * abs(d[bb] - d[i]) % MOD;
      ans += y;
      ans %= MOD;
    }
  };
  for (int i = 0; i < N; ++i) {
    f(f, i);
  }
  ans *= fp(comb(N, K), MOD - 2);
  ans %= MOD;
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