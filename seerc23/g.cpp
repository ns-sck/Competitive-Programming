#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int inf = 1ll << 61;
void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  vector<int> a(N), b(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<array<int, 3>> q;
  q.push({0, 0, 0});
  vector<array<vector<int>, 2>> lst(N, array<vector<int>, 2>());
  vector<int> dist(N, inf);
  vector<int> ans(N, -inf);
  vector<vector<int>> adj2(N);
  dist[0] = 0;
  while (q.size()) {
    auto [u, d, rep] = q.front();
    q.pop();
    assert(dist[u] == d);
    for (int& v : adj[u]) {
      if (!u) {
        q.push({v, d + 1, v});
        adj2[u].push_back(v);
        dist[v] = 1;
        ans[v] = a[u] - b[u];
      } else {
        ans[v] = max(ans[v], a[u] - b[u]);
        if (dist[v] == d) {
          lst[v][1].push_back(rep);
        } else if (dist[v] == d + 1) {
          lst[v][0].push_back(rep);
        } else if (dist[v] == d + 2) {
          assert(0);
        } else if (dist[v] == inf) {
          dist[v] = d + 1;
          adj2[u].push_back(v);
          q.push({v, d + 1, rep});
        }
      }
    }
  }
  vector<int> eqs, ones, glans(N, -inf);
  int eqans = -inf, sqans = -inf;
  auto dfs = [&](auto&& self, int u, int p) -> void {
    int in1 = eqs.size(), in2 = ones.size();
    for (int& x : lst[u][0]) eqs.push_back(x); 
    for (int& x : lst[u][1]) ones.push_back(x); 
    for (int& v : adj2[u]) {
      if (!u) {
        eqans = -inf, sqans = -inf;
        eqs = vector<int>(), ones = vector<int>();
      }
      ans[v] = max(ans[v], a[u] - b[u]);
      self(self, v, u);
    }
    ans[u] = max(ans[u], eqans);
    glans[u] = a[u] - (dist[u] + 1) * b[u];
    eqans = max(eqans, a[u] - dist[u] * b[u] + b[u]);
    sqans = max(sqans, a[u] - dist[u] * b[u]);
    while (eqs.size() > in1) {
      ans[eqs.back()] = max(ans[eqs.back()], eqans);
      eqs.pop_back();
    }
    while (ones.size() > in2) {
      ans[ones.back()] = max(ans[ones.back()], sqans);
      ones.pop_back();
    }
  };
  dfs(dfs, 0, -1);
  sort(adj[0].begin(), adj[0].end());
  for (int i = inf, mx = -inf; i < N; ++i) {
    ans[i] = max(ans[i], mx);
    mx = max(mx, glans[i]);
  }
  for (int i = N - 1, mx = -inf; i >= 0; --i) {
    ans[i] = max(ans[i], mx);
    mx = max(mx, glans[i]);
  }
  for (int& v : adj[0]) {
    cout << ans[v] << ' ';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t = 1; // cin >> t;
  while (t--) {
      solve();
  }
  
  return 0;
}