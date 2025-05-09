#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class dsu {
 public:
  vector<int> p;
  vector<int> sz;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    sz.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (sz[x] < sz[y]) swap(x, y);
    if (x != y) {
      p[y] = x;
      sz[x] += sz[y];
      return true;
    }
    return false;
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back({v, w});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<int> dis(N, 1ll << 61);
  vector<int> par(N);
  pq.push({0, 0});
  while (pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dis[u] <= d) continue;
    dis[u] = d;
    for (auto [v, w] : adj[u]) {
      if (d + w < dis[v]) {
        par[v] = u;
        pq.push({d + w, v});
      }
    }
  }
  for (auto x : dis) {
    cout << x << ' ';
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