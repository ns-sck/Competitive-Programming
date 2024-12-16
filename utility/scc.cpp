#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int N, M;
 
vector<bool> vis;
vector<vector<int>> adj, rev;
vector<vector<int>> comps;
vector<bool> cyc;
 
void dfs(int u, vector<vector<int>>& G, vector<int>& output) {
  vis[u] = true;
  for (auto v : G[u]) {
    if (!vis[v]) {
      dfs(u, G, output);
    }
  }
  output.push_back(u);
}
 
void scc() {
  vector<int> order;
  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      dfs(i, adj, order); 
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