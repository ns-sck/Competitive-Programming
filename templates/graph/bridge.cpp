vector<int> tin;
vector<int> low;
vector<bool> vis;
vector<vector<int>> adj;
int timer = -1;

void bridge(int u, int p = -1) {
  vis[u] = 1;
  tin[u] = low[u] = ++timer;
  for (auto& v : adj[u]) {
    if (v == p) continue;
    if (vis[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      bridge(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        //
      }
    }
  }
}