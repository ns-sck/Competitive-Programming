#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int N, M;
 
vector<bool> vis;
vector<vector<int>> adj, rev;
vector<vector<int>> comps;
vector<int> cmp;
 
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
  vector<int> order;
  for (int i = 1; i < 2 * N + 1; i++) {
    if (!vis[i]) {
      dfs(i, adj, order); 
    }
  }
  vis.assign(2 * N + 1, 0);
  reverse(order.begin(), order.end());
  for (auto u : order) {
    if (vis[u]) continue;
    vector<int> comp;
    dfs(u, rev, comp);  
    for (auto& x : comp) {
      cmp[x] = comps.size();
    }
    comps.push_back(comp);
  }
}

void solve() {
  cin >> N;
  vector<queue<int>> seen(2 * N + 1);
  vector<vector<int>> arr(3, vector<int>(N));
  adj.assign(2 * N + 1, {});
  rev.assign(2 * N + 1, {});
  comps.assign(0, {});
  cmp.assign(2 * N + 1, 0);
  vis.assign(2 * N + 1, 0);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < N; ++j) {
      auto& ref = arr[i][j];
      cin >> ref;
      if (ref > 0) ref += N;
      else ref = abs(ref);
    } 
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (abs(arr[j][i] - arr[k][i]) == N) {
          for (int z = 0; z < 3; ++z) {
            if (z == j || z == k) continue;
            adj[arr[j][i]].emplace_back(arr[z][i]);
            adj[arr[k][i]].emplace_back(arr[z][i]);
            rev[arr[z][i]].emplace_back(arr[k][i]);
            rev[arr[z][i]].emplace_back(arr[j][i]);
          }
        }
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      int x = arr[j][i], y;
      if (x <= N) y = x + N;
      else y = x - N;
      while (seen[y].size()) {
        int idx = seen[y].front();
        seen[y].pop();
        for (int k = 0; k < 3; ++k) {
          if (arr[k][idx] == y || arr[k][idx] == x) continue;
          adj[x].emplace_back(arr[k][idx]);
          rev[arr[k][idx]].emplace_back(x);
        }
      }
      seen[x].emplace(i);
    }
  }
  seen.assign(2 * N + 1, {});
  for (int i = N - 1; ~i; --i) {
    for (int j = 0; j < 3; ++j) {
      int x = arr[j][i], y;
      if (x <= N) y = x + N;
      else y = x - N;
      while (seen[y].size()) {
        int idx = seen[y].front();
        seen[y].pop();
        for (int k = 0; k < 3; ++k) {
          if (arr[k][idx] == y) continue;
          adj[x].emplace_back(arr[k][idx]);
          rev[arr[k][idx]].emplace_back(x);
        }
      }
      seen[x].emplace(i);
    }
  }
  scc();
  bool ok = 1;
  for (int i = 1; i <= N; ++i) {
    ok &= cmp[i] != cmp[i + N];
  }
  if (ok) cout << "YES\n";
  else cout << "NO\n";
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