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
  int N, A, B;
  cin >> N >> A >> B;
  dsu d1(N), d2(N);
  vector<pair<int, int>> a, b;
  int ans = 0;
  for (int i = 0; i < A; ++i) {
    int u, v;
    cin >> u >> v;
    a.emplace_back(u - 1, v - 1);
  }
  for (int i = 0; i < B; ++i) {
    int u, v;
    cin >> u >> v;
    d2.unite(u - 1, v - 1);
    b.emplace_back(u - 1, v - 1);
  }
  vector<pair<int, int>> c;
  for (auto [x, y] : a) {
    if (d2.get(x) != d2.get(y)) {
      ++ans;
    } else {
      c.emplace_back(x, y);
    }
  }
  for (auto [x, y] : c) {
    d1.unite(x, y);
  }
  for (auto [x, y] : b) {
    if (d1.unite(x, y)) {
      ++ans;
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}