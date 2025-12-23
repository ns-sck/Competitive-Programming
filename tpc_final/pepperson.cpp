#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<array<int, 2>>> adj2(N * 3);
  vector<vector<array<int, 2>>> par(N * 3, vector<array<int, 2>>(19, {-1, -1}));
  vector<bool> vis(N * 3);
  map<pair<int, int>, int> indis;
  int root = -1;
  for (int i = 0; i < N; ++i) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (root == -1) {
      root = a;
      adj2[a].push_back({b, min(d, e + f)});
      adj2[a].push_back({c, min(f, d + e)});
      par[b][0] = {a, min(d, e + f)};
      par[c][0] = {a, min(f, d + e)};
    } else {
      if (vis[a]) {
        adj2[a].push_back({b, min(d, e + f)});
        par[b][0] = {a, min(d, e + f)};
        adj2[a].push_back({c, min(f, d + e)});
        par[c][0] = {a, min(f, d + e)};
      } else if (vis[b]) {
        adj2[b].push_back({a, min(d, e + f)});
        par[a][0] = {b, min(d, e + f)};
        adj2[b].push_back({c, min(e, d + f)});
        par[c][0] = {b, min(e, d + f)};
      } else {
        adj2[c].push_back({a, min(f, d + e)});
        par[a][0] = {c, min(f, d + e)};
        adj2[c].push_back({b, min(e, d + f)});
        par[b][0] = {c, min(e, d + f)};
      }
    }
    indis[{min(a, b), max(a, b)}] = min(d, e + f);
    indis[{min(a, c), max(a, c)}] = min(f, d + e);
    indis[{min(b, c), max(b, c)}] = min(e, d + f);
    vis[a] = vis[b] = vis[c] = 1;
  }
  for (int i = 1; i < 19; ++i) {
    for (int j = 0; j < 3 * N; ++j) {
      if (par[j][i - 1][0] == -1) continue;
      par[j][i] = {par[par[j][i - 1][0]][i - 1][0], par[j][i - 1][1] + par[par[j][i - 1][0]][i - 1][1]};
    }
  }
  int timer = 0;
  vector<int> in(N * 3), out(N * 3);
  auto dfs = [&](auto&& self, int u) -> void {
    in[u] = ++timer;
    for (auto& [v, d] : adj2[u]) {
      self(self, v);
    }
    out[u] = ++timer;
  };
  dfs(dfs, root);
  auto anc = [&](int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
  };
  auto lca = [&](int u, int v) {
    int ans = 0;
    for (int j = 18; j >= 0; j--) {
      if (par[u][j][0] != -1 && !anc(par[u][j][0], v)) {
        ans += par[u][j][1];
        u = par[u][j][0];
      }
      if (par[v][j][0] != -1 && !anc(par[v][j][0], u)) {
        ans += par[v][j][1];
        v = par[v][j][0];
      }
    }
    int a = indis[{min(u, v), max(u, v)}];
    if (a != 0) {
      return ans + a;
    } else {
      return ans + par[u][0][1] + par[v][0][1];
    }
  };
  while (M--) {
    int u, v;
    cin >> u >> v;
    if (u == v) {
      cout << 0 << '\n';
    } else {
      cout << lca(u, v) << '\n';
    }
  }
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