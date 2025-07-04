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
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> adj(N);
  vector<array<int, 3>> edges;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.push_back({w, u, v});
  }
  sort(edges.begin(), edges.end());
  vector<int> arr(K);
  for (int& x : arr) cin >> x;
  sort(arr.begin(), arr.end());
  vector<int> best;
  dsu d(N);
  int ans = 0;
  for (auto [z, x, y] : edges) {
    if (d.unite(x, y)) {
      ans += z;
      best.emplace_back(z);
    }
  }
  int i = 0, j = best.size() - 1;
  int comp = N - best.size();
  for (int k = 0; k < comp - 1; ++k) {
    cout << 0 << ' ';
    ans += arr[i++];
  }
  for (int k = comp - 1; k <= K; ++k) {
    while (i < k) {
      ans += arr[i] - best[j];
      ++i, --j;
    }
    cout << ans << " \n"[k == K];
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