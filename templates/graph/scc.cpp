int N, M;
vector<bool> vis;
vector<vector<int>> adj, rev;
vector<vector<int>> comps;
vector<bool> cyc;
 
void dfs(int u, vector<vector<int>>& G, vector<int>& output) {
  vis[u] = true;
  for (auto v : G[u]) {
    if (!vis[v]) {
      dfs(v, G, output);
    }
  }
  output.push_back(u);
}
 
void scc() {
  rev = vector<vector<int>>(N);
  vis = vector<bool>(N);
  cyc = vector<bool>(N);
  vector<int> order;
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      dfs(i, adj, order); 
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int& j : adj[i]) {
      rev[j].push_back(i);
    }
  }
  vis.assign(N, 0);
  reverse(order.begin(), order.end());
  for (auto u : order) {
    if (vis[u]) continue;
    vector<int> comp;
    dfs(u, rev, comp);  
    sort(comp.begin(), comp.end());
    comps.push_back(comp);
  }
}