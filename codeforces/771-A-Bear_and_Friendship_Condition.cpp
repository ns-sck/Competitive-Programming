#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// tourist
class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<array<int, 2>> edges;
  vector<int> ecnt(N);
  dsu d(N);
  while (M--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d.unite(u, v);
    edges.push_back({u, v});
    // ecnt[d.get(u)]++;
  }
  for (auto [x, y] : edges) {
    ecnt[d.get(x)]++;
  }
  vector<int> comp(N);
  for (int i = 0; i < N; ++i) {
    comp[d.get(i)]++;
  }
  for (int i = 0; i < N; ++i) {
    int x = comp[i], y = ecnt[i];
    if (x * (x - 1) / 2 != y) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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