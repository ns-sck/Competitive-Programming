#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

int cnt;

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

  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      if (sz[x] < sz[y]) swap(x, y);
      cnt -= sz[x] * sz[y];
      p[y] = x;
      sz[x] += sz[y];
      return true;
    }
    return false;
  }
};

void solve() {
  int N, M, Q;
  cin >> N >> M >> Q;
  assert(1 <= N <= 1e5);
  assert(1 <= M <= 2e5);
  assert(1 <= Q <= 2e5);
  vector<vector<array<int, 2>>> adj(N);
  vector<array<int, 3>> edges;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    assert(1 <= u <= N);
    assert(1 <= v <= N);
    assert(1 <= w <= 1e9);
    --u, --v;
    edges.push_back({w, u, v});
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<array<int, 2>> qrs(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> qrs[i][0];
    assert(1 <= qrs[i][0] <= N * (N - 1) / 2);
    qrs[i][1] = i;
  }
  sort(qrs.rbegin(), qrs.rend());
  sort(edges.begin(), edges.end());
  cnt = N * (N - 1) / 2;
  dsu d(N);
  int old = edges[0][0];
  int qptr = 0;
  vector<int> ans(Q);
  for (auto& [w, u, v] : edges) {
    if (w != old) {
      while (qptr < Q && cnt < qrs[qptr][0]) {
        ans[qrs[qptr][1]] = old;
        qptr++;
      }
      old = w;
    }
    d.unite(u, v);
  }
  while (qptr < Q && cnt < qrs[qptr][0]) {
    ans[qrs[qptr++][1]] = old;
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << " \n"[i == Q - 1];
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