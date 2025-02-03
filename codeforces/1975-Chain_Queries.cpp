#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<bool> color(N);
  vector<vector<int>> adj(N);
  vector<int> par(N, -1);
  vector<int> ch(N);
  vector<int> dep(N);
  int node = 0, edge = 0, root = -1, two = 0;
  for (int i = 0; i < N; ++i) {
    bool b;
    cin >> b;
    color[i] = b;
    node += b;
  }
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dep[0] = 0;
  priority_queue<pair<int, int>> pq;
  auto dfs = [&](auto&& f, int u, int p) -> void {
    int c = 0;
    if (color[u]) {
      pq.emplace(-dep[u], u);
    }
    for (auto& v : adj[u]) {
      if (v == p) continue; 
      dep[v] = dep[u] + 1;
      f(f, v, u);
      par[v] = u;
      if (color[v]) {
        ++c;
        edge += color[u];
      }
    }
    ch[u] = c;
  };
  dfs(dfs, 0, -1);
  for (int i = 0; i < N; ++i) {
    two += (color[i] && ch[i] >= 2);
  }
  while (Q--) {
    int u;
    cin >> u;
    --u;
    int p = par[u];
    if (color[u]) {
      color[u] = 0;
      --node;
      if (p != -1) {
        --ch[p];
        if (color[p]) {
          --edge;
          if (ch[p] == 1) {
            --two;
          }
        }
      }
      if (ch[u] >= 2) --two;
      edge -= ch[u];
    } else {
      color[u] = 1;
      pq.emplace(-dep[u], u);
      ++node;
      if (p != -1) {
        ++ch[p];
        if (color[p]) {
          ++edge;
          if (ch[p] == 2) {
            ++two;
          }
        }
      }
      if (ch[u] >= 2) ++two;
      edge += ch[u];
    }
    if (edge != node - 1) {
      cout << "NO\n";
      continue;
    } 
    root = -1;
    while (pq.size()) {
      auto [d, x] = pq.top();
      if (color[x]) {
        root = x;
        break;
      }
      pq.pop();
    }
    if ((two > 1) || (two && ch[root] != 2)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
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