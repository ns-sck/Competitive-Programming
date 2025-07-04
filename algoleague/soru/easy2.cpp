#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<array<int, 2>>> adj(N);
  map<pair<int, int>, int> seen;
  int mx = 0;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    mx = max(mx, w);
    seen[{u, v}]++;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for (auto [x, y] : seen) {
    assert(y <= 1);
  } 
  int lo = -1, hi = mx, best = -1;
  while (lo <= hi) {
    int mi = (lo + hi) / 2;
    vector<bool> vis(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (vis[i]) continue;
      int c = 0;
      vector<int> q = {i};
      for (int j = 0; j < q.size(); ++j) {
        int u = q[j];
        c++;
        vis[u] = 1;
        for (auto& [v, w] : adj[u]) {
          if (!vis[v] && w < mi) {
            vis[v] = 1;
            q.push_back(v);
          }
        }
      }
      ans += c * (N - c);
    }
    if (ans / 2 >= K) {
      best = mi;
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  cout << best << '\n';
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