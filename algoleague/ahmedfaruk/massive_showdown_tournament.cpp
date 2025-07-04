#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 5e4 + 1;

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
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<vector<int>> divs(MAX);
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j * j <= arr[i]; ++j) {
      if (arr[i] % j) continue;
      divs[j].emplace_back(i);
      if (j != arr[i] / j) divs[arr[i] / j].emplace_back(i);
    }
  }
  dsu d(N);
  int edge = N - 1, j = MAX - 1, ans = 0;
  while (edge) {
    if (divs[j].size() >= 2) {
      for (int i = 1; i < divs[j].size(); ++i) {
        if (d.unite(divs[j][i - 1], divs[j][i])) {
          --edge;
          ans += j;
        }
      }
    }
    --j;
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