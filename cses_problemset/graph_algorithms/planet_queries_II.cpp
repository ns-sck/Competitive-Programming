#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> adj(N);
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    adj[v - 1].emplace_back(i);
  }
  vector<bool> vis(N);
  vector<bool> act(N);
  vector<int> rank(N);
  vector<int> cyc(N);
  vector<int> cc(N);
  vector<int> comp(N);
  vector<vector<int>> lca(N, vector<int>(20, -1));
  int a = 0;
  int cmp = 0;
  auto dfs = [&](auto&& self, int u) -> void {
    act[u] = vis[u] = 1;
    for (auto& v : adj[u]) {
      if (act[v]) {
        lca[v][0] = u;
        int r = 1;
        int x = u;
        int nc = 1;
        rank[v] = r++;
        cyc[v] = a;
        while (x != v) {
          rank[x] = r++;
          nc++;
          x = lca[x][0];
          cyc[x] = a;
        }
        cc[a] = nc;
        a++;
        cmp++;
      } else if (!vis[v]) {
        lca[v][0] = u;
        self(self, v);
      }
    }
    act[u] = 0;
  };
  for (int i = 0; i < N; ++i) {
    if (vis[i]) continue;
    dfs(dfs, i);
  }
  vector<int> in(N);
  vector<int> out(N);
  int timer = 0;
  auto dfs2 = [&](auto&& self, int u) -> void {
    in[u] = timer++;
    comp[u] = cmp;
    vis[u] = 1;
    for (auto& v : adj[u]) {
      if (vis[v]) continue;
      lca[v][0] = u;
      self(self, v);
    }
    out[u] = timer++;
  };
  vis.assign(N, 0);
  for (int i = 0; i < N; ++i) {
    if (vis[i] || !rank[i]) continue;
    dfs2(dfs2, i);
    cmp++;
  }
  auto anc = [&](int u, int v) -> bool {
    return rank[u] || u == -1 || in[u] <= in[v] && out[u] >= out[v];
  };
  for (int i = 1; i < 20; ++i) {
    for (int u = 0; u < N; ++u) {
      if (lca[u][i - 1] == -1) continue;
      lca[u][i] = lca[lca[u][i - 1]][i - 1];
    }
  }
  while (Q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (!anc(v, u) || comp[u] != comp[v]) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 0;
    if (!rank[u] && !anc(u, v)) {
      for (int i = 19; ~i; --i) {
        int p = lca[u][i];
        if (!anc(p, v)) {
          u = p;
          ans += 1 << i;
        }
      }
      u = lca[u][0];
      ans++;
    }
    if (u == v) {
      cout << ans << '\n';
    } else {
      assert(rank[u] && rank[v]);
      int nc = cc[cyc[u]];
      int z = (rank[v] - rank[u] + nc) % nc;
      cout << ans + z << '\n';
    }
  }
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