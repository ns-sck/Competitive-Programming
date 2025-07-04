#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  assert(2 <= N <= 1500);
  vector<vector<int>> adj(N);
  vector<vector<int>> mtx(N, vector<int>(N));
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    assert(1 <= u <= N);
    assert(1 <= v <= N);
    --u, --v;
    mtx[u][v] = mtx[v][u] = 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int Q;
  cin >> Q;
  assert(1 <= Q <= 1500);
  while (Q--) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    assert(1 <= u <= N);
    assert(1 <= v <= N);
    assert(1 <= x <= N);
    assert(1 <= y <= N);
    --u, --v, --x, --y;
    assert(mtx[u][v]);
    mtx[u][v] = mtx[v][u] = 0;
    if (u > v) swap(u, v);
    if (x > y) swap(x, y);
    if (x == y) {
      cout << "NO\n";
    } else if (u == x && v == y) {
      cout << "YES\n";
    } else {
      vector<int> que = {0};
      vector<bool> vis(N);
      int c = 0;
      for (int i = 0; i < que.size(); ++i) {
        int u = que[i];
        vis[u] = 1;
        ++c;
        for (auto& v : adj[u]) {
          if (!vis[v] && mtx[u][v]) {
            vis[v] = 1;
            que.push_back(v);
          }
        }
        if (u == x && !vis[y]) {
          vis[y] = 1;
          que.push_back(y);
        }
        if (u == y && !vis[x]) {
          vis[x] = 1;
          que.push_back(x);
        }
      }
      // debug(c, N);
      if (c == N) cout << "YES\n";
      else cout << "NO\n";
    }
    mtx[u][v] = mtx[v][u] = 1;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}