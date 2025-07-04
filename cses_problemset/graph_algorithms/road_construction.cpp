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
  dsu d(N);
  int ans = N, mx = 1;
  while (M--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (d.unite(u, v)) {
      ans--;
    }
    mx = max(mx, max(d.sz[d.get(u)], d.sz[d.get(v)]));
    cout << ans << ' ' << mx << '\n';
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