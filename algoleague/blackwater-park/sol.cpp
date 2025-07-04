#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  vector<int> dis_down(N), dis_up(N), size_down(N), size_up(N), in(N), out(N);
  vector<vector<array<int, 2>>> par(N, vector<array<int, 2>>(20));
  int timer = 0;
  auto dfs1 = [&](auto&& self, int u, int p) -> void {
    in[u] = timer++;
    for (auto [v, w] : adj[u]) {
      if (v == p) continue;
      par[v][0] = {u, w};
      self(self, v, u);
      size_down[u] += size_down[v] + 1;
      dis_down[u] += dis_down[v] + (size_down[v] + 1) * w;
    }
    out[u] = timer++;
  };
  auto dfs2 = [&](auto&& self, int u, int p) -> void {
    if (~p) {
      int sibsz = size_down[p] - size_down[u] - 1;
      int sibdis = dis_down[p] - (dis_down[u] + (size_down[u] + 1) * par[u][0][1]);
      size_up[u] = size_up[p] + sibsz + 1;
      dis_up[u] = dis_up[p] + sibdis + (size_up[p] + 1 + sibsz) * par[u][0][1];
    }
    for (auto [v, w] : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
  };
  dfs1(dfs1, 0, -1);
  dfs2(dfs2, 0, -1);
  int z, diz;
  for (int i = 1; i < 20; ++i) {
    for (int u = 0; u < N; ++u) {
      int p = par[u][i - 1][0];
      if (p == -1) continue;
      par[u][i][0] = par[p][i - 1][0];
      par[u][i][1] = par[u][i - 1][1] + par[p][i - 1][1];
    }
  }
  auto ancestor = [&](int u, int v) -> bool {
    return u == 0 || (in[u] <= in[v] && out[u] >= out[v]); 
  };
  auto dist = [&](int u, int v) -> int {
    if (u == v) return 0;
    int dis = 0;
    for (int i = 19; ~i; --i) {
      if (!ancestor(par[v][i][0], u)) {
        dis += par[v][i][1];
        v = par[v][i][0];
      }
    }
    z = v, diz = par[v][0][1];
    return diz + dis;
  };
  auto lca = [&](int u, int v) -> int {
    for (int j = 19; ~j; --j) {
      if (!ancestor(par[u][j][0], v)) {
        u = par[u][j][0];
      }
      if (!ancestor(par[v][j][0], u)) {
        v = par[v][j][0];
      }
    }
    if (!ancestor(u, v)) {
      return par[u][0][0];
    }
    return par[v][0][0];
  };
  // chain u -> v
  auto get_branches = [&](int u, int v) -> int {
    int dis = dist(u, v) - diz;
    int low = dis_down[z] - (dis_down[v] + size_down[v] * dis);
    int up = dis_up[v] - (dis_up[z] + size_up[z] * dis);
    int cnt = size_down[z] - size_down[v] + 1;
    // low + up = 2 * x + dis
    return (low + up - cnt * dis) / 2;
  };
  while (Q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u == v) {
      cout << dis_down[u] + dis_up[v] << '\n';
    } else if (ancestor(u, v) || ancestor(v, u)) {
      if (ancestor(v, u)) swap(v, u);
      int a = get_branches(u, v);
      int b = dis_down[u] - (dis_down[z] + (size_down[z] + 1) * diz);
      cout << a + dis_down[v] + dis_up[u] + b << '\n';
    } else {
      int anc = lca(u, v);
      int a = get_branches(anc, u);
      int ch1 = z, dis = diz;
      int b = get_branches(anc, v);
      int c = dis_down[anc] - (dis_down[z] + (size_down[z] + 1) * diz) - (dis_down[ch1] + (size_down[ch1] + 1) * dis);
      cout << dis_down[v] + dis_down[u] + dis_up[anc] + c + a + b << '\n';
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