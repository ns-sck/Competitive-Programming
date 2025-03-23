#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, -- v;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  vector<int> dis(N, 1ll << 59);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.emplace(0, 0);
  while (pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dis[u] <= d) continue;
    dis[u] = d;
    for (auto& [v, w] : adj[u]) {
      if ((d | w) < dis[v]) { 
        pq.emplace(d | w, v);
      }
    }
  }
  vector<int> dis2(N, 1ll << 59);
  pq.emplace(0, N - 1);
  while (pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dis2[u] <= d) continue;
    dis2[u] = d;
    for (auto& [v, w] : adj[u]) {
      if ((d | w) < dis2[v]) { 
        pq.emplace(d | w, v);
      }
    }
  }
  int ans = 1ll << 59;
  for (int i = 0; i < N; ++i) {
    ans = min(ans, dis[i] | dis2[i]);
  }
  priority_queue<pair<int, int>> pq2;
  pq2.emplace(0, 0);
  int c = 0;
  dis.assign(N, 1ll << 59);
  while (pq2.size()) {
    auto [d, u] = pq2.top();
    pq2.pop();
    if (c++ > 1e6) {
      break;
    }
    if (dis[u] <= d) continue;
    dis[u] = d;
    for (auto& [v, w] : adj[u]) {
      if ((d | w) < dis[v]) { 
        pq2.emplace(d | w, v);
      }
    }
  }
  ans = min(ans, dis[N - 1]);
  if (ans == (1ll << 59)) cout << 0 << '\n';
  else cout << ans << '\n';
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