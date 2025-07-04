#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M, Q, K;
  cin >> N >> M >> Q;
  vector<vector<array<int, 2>>> adj(N);
  int mx = 0;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    mx = max(mx, w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  auto f = [&](int K) {
    int lo = -1, hi = mx, best = -1;
    while (lo <= hi) {
      int mi = (lo + hi) / 2;
      vector<bool> vis(N);
      int ans = 0;
      for (int i = 0; i < N; ++i) {
        if (vis[i]) continue;
        int c = 0;
        queue<int> q;
        q.push(i);
        while (q.size()) {
          int u = q.front();
          q.pop();
          c++;
          vis[u] = 1;
          for (auto& [v, w] : adj[u]) {
            if (!vis[v] && w < mi) {
              vis[v] = 1;
              q.push(v);
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
    cout << best << ' ';
  };
  for (int i = 0; i < Q; ++i) {
    int q;
    cin >> q;
    f(q);
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