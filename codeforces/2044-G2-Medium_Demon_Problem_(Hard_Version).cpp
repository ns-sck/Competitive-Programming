#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int N, M;

vector<bool> vis;
vector<vector<int>> adj, rev;
vector<vector<int>> comps;
vector<bool> cyc;
 
void dfs(int v, vector<vector<int>>& a, vector<int>& output) {
  vis[v] = true;
  for (auto u : a[v])
    if (!vis[u])
      dfs(u, a, output);
  output.push_back(v);
}
 
void scc() {
 
  vector<int> order;
  for (int i = 1; i <= N; i++)
    if (!vis[i])
        dfs(i, adj, order);
  for (int v = 1; v <= N; v++)
    for (int u : adj[v])
        rev[u].push_back(v);
  vis.assign(N, 0);
  reverse(order.begin(), order.end());
  vector<int> roots(N + 1);
  for (auto v : order)
    if (!vis[v]) {
      vector<int> comp;
      dfs(v, rev, comp);  
      sort(comp.begin(), comp.end());
      comps.push_back(comp);
      int root = comp.front();
      for (auto u : comp) {
        roots[u] = root;
        if (comp.size() > 1) cyc[u] = 1;
      }
    }
}

void solve() {
  cin >> N;
  vis.assign(N + 1, 0);
  adj.assign(N + 1, {});
  rev.assign(N + 1, {});
  comps.assign(0, {});
  cyc.assign(N + 1, 0);
  vector<int> indg(N + 1);
  for (int i = 1; i <= N; ++i) {
    int j;
    cin >> j;
    adj[i].emplace_back(j);
    ++indg[j];
  }
  scc();
  int ans = 2;
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (!indg[i]) q.emplace(i);
  }
  vector<int> has(N + 1, 1);
  vis.assign(N + 1, 0);
  while(q.size()) {
    int u = q.front();
    if (cyc[u]) continue;
    ans = max(ans, has[u] + 2);
    q.pop();
    for (auto v : adj[u]) {
      has[v] += has[u];
      if (--indg[v] == 0) {
        q.emplace(v);
      }
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}