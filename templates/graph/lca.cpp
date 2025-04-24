void build_lca() {
  for (int i = 0; i < n; ++i) {
    pr[i] = vector<int>(h, -1);
    pr[i][0] = par[i];
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
    }
  }
}

inline bool anc(int u, int v) {
  return in[u] <= in[v] && out[u] >= out[v];
}

inline int find_lca(int u, int v) {
  assert(!pr.empty());
  if (anc(x, y)) {
    return x;
  }
  if (anc(y, x)) {
    return y;
  }
  for (int j = h - 1; j >= 0; j--) {
    if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
      x = pr[x][j];
    }
  }
  return pr[x][0];
}

inline int go_up(int u, int up) {
  assert(!pr.empty());
  up = min(up, (1 << h) - 1);
  for (int j = h - 1; j >= 0; j--) {
    if (up & (1 << j)) {
      u = pr[u][j];
      if (u == -1) {
        break;
      }
    }
  }
  return u;
}