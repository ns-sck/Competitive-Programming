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
/*
9 12
1 2 11
1 3 7
1 5 8
5 6 4
2 7 9
6 7 6
4 7 1
4 3 2
7 8 8
9 7 10
9 8 7
4 9 2
*/
void solve() {
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> edges(M);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {w, u, v};
  }
  sort(edges.begin(), edges.end());
  dsu d(N + 1);
  int ans = 0;
  for (auto [w, u, v] : edges) {
    if (d.get(u) == d.get(v)) continue;
    ans += w;
    d.unite(u, v);
  }
  cout << ans << '\n';
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