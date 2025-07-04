#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

struct dsu {
  int n;
  vector<int> par;
  vector<int> size;
  dsu(int _n) {
    n = _n;
    par = vector<int>(n);
    iota(par.begin(), par.end(), 0);
    size = vector<int>(n, 1);
  }

  int find(int u) {
    if (par[u] == u) {
      return u;
    }
    // int v = find(par[u]);
    // par[u] = v;
    return par[u] = find(par[u]);
  }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return false;
    }
    if (size[v] > size[u]) {
      swap(v, u);
    }
    par[v] = u;
    return true;
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> edges;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.push_back({w, u, v});
  }
  dsu d(N);
  sort(edges.begin(), edges.end());
  int ans = 0;
  for (auto [w, u, v] : edges) {
    if (d.merge(u, v) == true) {
      ans += w;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}