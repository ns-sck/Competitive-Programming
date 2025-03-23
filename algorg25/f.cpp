#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// tourist
class dsu {
 public:
  vector<int> p, color;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    color.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    if (x >= n) {
      cout << 'y';
    }
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
  vector<string> g(N);
  for (string& s : g) cin >> s;
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  vector<vector<int>> vis(N, vector<int>(M));
  dsu d(N * M + 1);
  char a;
  auto ok = [&](int i, int j) {
    return ~i && i < N && ~j && j < M;
  };
  vector<vector<int>> adj(N * M + 1, vector<int>());
  while (q.size()) {
    auto [i, j] = q.front();
    q.pop();
    if (!ok(i, j)) continue;
    if (vis[i][j]) continue;
    vis[i][j] = 1;
    a = g[i][j];
    d.color[d.get(i * M + j)] = a == '1';
    q.emplace(i, j + 1);
    if (ok(i, j + 1)) {
      if (g[i][j] == g[i][j + 1]) {
        d.unite(i * M + j, i * M + j + 1);
      } else {
        adj[i * M + j].emplace_back(i * M + j + 1);
        adj[i * M + j + 1].emplace_back(i * M + j);
      }
    }
    q.emplace(i + 1, j);
    if (ok(i + 1, j)) {
      if (g[i][j] == g[i + 1][j]) {
        d.unite(i * M + j, (i + 1) * M + j);
      } else {
        adj[i * M + j].emplace_back(i * M + M + j);
        adj[i * M + M + j].emplace_back(i * M + j);
      }
    }
    int x = (i & 1) == 1 ? -1 : 1;
    q.emplace(i - 1, j + x);
    if (ok(i - 1, j + x)) {
      if (g[i][j] == g[i - 1][j + x]) {
        d.unite(i * M + j, (i - 1) * M + j + x);
      } else {
        adj[i * M + j].emplace_back(i * M - M + j + x);
        adj[i * M - M + j + x].emplace_back(i * M + j);
      }
    }
    q.emplace(i + 1, j + x);
    if (ok(i + 1, j + x)) {
      if (g[i][j] == g[i + 1][j + x]) {
        d.unite(i * M + j, (i + 1) * M + j + x);
      } else {
        adj[i * M + j].emplace_back(i * M + M + j + x);
        adj[i * M + M + j + x].emplace_back(i * M + j);
      }
    }
  } 
  int node, best = -1;
  auto dfs = [&](auto&& self, int u, int p, int d) -> void {
    if (d > best) {
      node = u;
      best = d;
    }
    for (auto& v : adj[u]) {
      if (v == p) continue;
      self(self, v, u, d + 1);
    }
  };
  dfs(dfs, d.get(0), -1, 0);
  best = - 1;
  dfs(dfs, best, -1, 0);
  if (best & 1) {
    cout << (best + 1) / 2 << endl;
  } else {
    int p = d.color[d.get(node)];
    cout << best / 2 + (p == 0) << endl;
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