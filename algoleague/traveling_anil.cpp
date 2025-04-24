#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  assert(1 <= N <= (int) 2e5);
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    assert(1 <= u <= N);
    assert(1 <= v <= N);
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int root = 0, dia = 0, dest = -1;
  vector<int> on(N);
  auto dfs = [&](auto&& self, int u, int p, int d) -> bool {
    if (d >= dia) {
      dia = d;
      root = u;
    }
    for (int& v : adj[u]) {
      if (v == p) continue;
      on[u] |= self(self, v, u, d + 1);
    }
    return on[u] |= (u == dest);
  };
  dfs(dfs, 0, -1, 0);
  dest = root;
  dfs(dfs, root, -1, 0);
  dfs(dfs, root, -1, 0);
  vector<int> ans;
  auto dfs2 = [&](auto&& self, int u, int p, int d) -> int {
    int mx1 = -1, mx2 = -1;
    for (int& v : adj[u]) {
      if (v == p) continue;
      int dis = self(self, v, u, d + 1) - d;
      if (!on[v]) {
        if (dis >= mx1) {
          mx2 = mx1;
          mx1 = dis;
        } else if (dis >= mx2) {
          mx2 = dis;
        }
      }
    }
    if (~mx1 && ~mx2 && mx1 + mx2 == dia) {
      cout << u + 1 << '\n';
      exit(0);
    } else if (~mx1 && mx1 + d == dia) {
      ans = {u};  
    } else if (on[u]) {
      ans.push_back(u);
      if (mx1 == d) {
        sort(ans.begin(), ans.end());
        for (int& x : ans) {
          cout << x + 1 << " \n"[x == ans.back()];
        }
        exit(0);
      }
    }
    return d + max((int) 0, mx1);
  };
  dfs2(dfs2, root, -1, 0);
  sort(ans.begin(), ans.end());
  for (int& x : ans) {
    cout << x + 1 << " \n"[x == ans.back()];
  }
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