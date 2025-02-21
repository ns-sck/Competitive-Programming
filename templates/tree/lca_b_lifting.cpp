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
    return dis + par[v][0][1];
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