int centroid_decomposition(int k) {
  vector<bool> alive(n, true);
  vector<int> csz(n);
  int ans = 0;
  auto Dfs = [&](auto&& self, int u, int p) -> void {
    csz[u] = 1;
    for (int eid : adj[u]) {
      auto& e = edges[eid];
      int v = e.from ^ e.to ^ u;
      if (v != p && alive[v]) {
        self(self, v, u);
        csz[u] += csz[v];
      }
    }
  };
  auto Build = [&](auto&& self, int u, int pc) -> void {
    Dfs(Dfs, u, -1);
    int c = u;
    int p = -1;
    while (true) {
      int nxt = -1;
      for (int eid : adj[c]) {
        auto& e = edges[eid];
        int v = e.from ^ e.to ^ c;
        if (v != p && alive[v] && 2 * csz[v] > csz[u]) {
          nxt = v;
          break;
        }
      }
      if (nxt == -1) break;
      p = c;
      c = nxt;
    }

    alive[c] = false;
    for (int eid : adj[c]) {
      auto& e = edges[eid];
      int v = e.from ^ e.to ^ c;
      if (alive[v]) {
        self(self, v, c);
      }
    }
  };

  for (int i = 0; i < n; i++) {
    if (alive[i]) {
      Build(Build, i, -1);
    }
  }
  return ans;
}