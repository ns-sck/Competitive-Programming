#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M, K, X, P;
  cin >> N >> M >> K >> X >> P;
  assert(1 <= N <= 1e4);
  assert(1 <= M <= 1e5);
  assert(1 <= P <= 1e2);
  vector<bool> boost(N);
  for (int i = 0; i < P; ++i) {
    int u;
    cin >> u;
    assert(1 <= u <= N);
    assert(!boost[u - 1]);
    boost[u - 1] = 1;
  }
  vector<vector<array<int, 2>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    assert(1 <= min(u, v) <= max(u, v) <= N);
    assert(X * K * P <= w);
    adj[u - 1].push_back({v - 1, w});
    adj[v - 1].push_back({u - 1, w});
  }
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
  vector<vector<int>> dis(N, vector<int>(1 << K, 1ll << 61));
  int S, T;
  cin >> S >> T;
  assert(1 <= min(S, T) <= max(S, T) <= N);
  --S, --T;
  pq.push({0, S, 0});
  dis[S][0] = 0;
  int msk = (1 << K) - 1;
  while (pq.size()) {
    auto [d, u, mask] = pq.top();
    pq.pop();
    if (dis[u][mask] < d) continue;
    int nw = ((mask << 1) & msk) + boost[u];
    for (auto& [v, w] : adj[u]) {
      int go = d + w - (__builtin_popcount(nw) * X);
      if (dis[v][nw] > go) {
        debug(nw);
        dis[v][nw] = go;
        pq.push({go, v, nw});
      }
    }
  }
  int ans = 1ll << 61;
  for (int i = 0; i < (1 << K); ++i) {
    ans = min(ans, dis[T][i]);
  }
  cout << ans << '\n';
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