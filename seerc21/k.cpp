#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  if (n == 2) {
    cout << "1 2\n";
    return;
  }
  priority_queue<int, vector<int>, greater<>> s; 
  for (int i = 1; i <= n; i++) if (adj[i].size() == 1) s.push(i);

  vector<int> vis(n + 1);
  int cad = adj[s.top()][0];
  debug(cad);
  int dg = adj[cad].size();

  vis[cad] = 1;

  auto dfs = [&](auto&& self, int from, int parent) -> void {
    vis[from] = 1;
    for (auto& to : adj[from]) {
      if (vis[to] || to == parent) continue;
      self(self, to, from);
    }
  };

  while (dg > 1) {
    if (!vis[s.top()]) {
      debug(s.top());
      dfs(dfs, s.top(), -1);
      dg--;
    }
    s.pop();
  }

  auto Chc = [&](int& cnd) -> bool {
    for (auto to : adj[cnd]) {
      if (!vis[to]) {
        cnd = to;
        return true;
      }
    }
    return false;
  };
  debug(vis);
  while (1) {
    debug(cad);
    while (!s.empty() && vis[s.top()]) s.pop();
    if (cad > s.top()) {
      break;
    }
    if (!Chc(cad)) break;
    dg = adj[cad].size() - 1;
    vis[cad] = 1;
    while (dg > 1) {
      if (!vis[s.top()]) {
        dfs(dfs, s.top(), -1);
        dg--;
      }
      s.pop();
    }
  }


  int root = cad;

  vector<int> vals(n + 1, 1e8);
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1) vals[i] = i;
  }

  auto AA = [&](auto&& self, int from, int parent) -> int {
    for (auto& to : adj[from]) {
      if (to == parent) continue;
      vals[from] = min(vals[from], self(self, to, from));
    }
    return vals[from];
  };

  AA(AA, root, -1);
  
  auto BB = [&](auto&& self, int from, int parent) -> void {
    vector<pair<int, int>> v;
    for (auto& to : adj[from]) {
      if (to == parent) continue;
      v.push_back({vals[to], to});
    }
    sort(v.begin(), v.end());
    for (auto [l, r] : v) {
      self(self, r, from);
    }
    cout << from << ' ';
  };
  debug(root);
  BB(BB, root, -1);
  cout << '\n';
  return;

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}