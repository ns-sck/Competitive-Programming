#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int N, M;
vector<bool> vis;
vector<vector<int>> adj, rev;
vector<vector<int>> comps;
vector<bool> cyc;
int tt = 0;
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

void solve() {
  cin >> N >> M;
  vector<int> arr(N);
  adj = vector<vector<int>>(N);
  for (int & x : arr) cin >> x;
  while (M--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
  }
  scc();
  int n = comps.size();
  vector<int> g(N);
  for (int i = 0; i < n; ++i) {
    for (int& j : comps[i]) {
      g[j] = i;
    }
  }
  vector<vector<int>> adj2(N);
  vector<int> arr2(n);
  for (int i = 0; i < N; ++i) {
    arr2[g[i]] += arr[i];
    for (int& j : adj[i]) {
      if (g[i] ^ g[j]) {
        adj2[g[i]].push_back(g[j]);
      }
    }
  }
  rev = {};
  comps = {};
  adj = {};
  vis = {};
  vector<int> out(n);
  vector<int> times(n << 2, -1);
  vector<bool> vis(n);
  int time = 0;
  auto dfs = [&](auto&& self, int u, int p) -> void {
    vis[u] = 1;
    for (int& v : adj2[u]) {
      if (v == p || vis[v]) continue;
      self(self, v, u);
    }
    times[time++] = u; 
  };
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(dfs, i, -1);
    }
  }
  vector<int> order;
  for (int i = 0; i < 4 * n - 1; ++i) {
    if (~times[i]) {
      order.push_back(times[i]);
    }
  }
  vector<vector<int>> rev(n);
  vector<int> best(n, 0);
  for (int i = 0; i < n; ++i) {
    best[i] = arr2[i];
    for (int& j : adj2[i]) {
      rev[j].push_back(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int& j : rev[order[i]]) {
      if (best[j] < best[order[i]] + arr2[j]) {
        best[j] = best[order[i]] + arr2[j];
      }
    }
  }
  cout << *max_element(best.begin(), best.end()) << '\n';
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