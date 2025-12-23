#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

vector<int> tin;
vector<int> low;
vector<bool> vis;
vector<bool> isbr;
set<int> nodes;
vector<vector<array<int, 3>>> adj;
int timer = -1;

void bridge(int u, int p = -1) {
  vis[u] = 1;
  tin[u] = low[u] = ++timer;
  for (auto& [v, w, idx] : adj[u]) {
    if (v == p) continue;
    if (vis[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      bridge(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        isbr[idx] = 1;
        nodes.insert(u);
        nodes.insert(v);
      }
    }
  }
}

void solve() {
  int N, M;
  cin >> N >> M;
  tin.resize(N);
  low.resize(N);
  vis.resize(N);
  isbr.resize(M);
  adj.resize(N);
  for (int i = 0, j = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back({v, w, j});
    adj[v].push_back({u, w, j++});
  }
  bridge(0);
  vector<int> comp(N);
  vector<bool> vis(N);
  int c = -1;
  for (int i = 0; i < N; ++i) {
    if (!vis[i]) {
      c++;
      queue<int> q;
      q.push(i);
      while (q.size()) {
        int u = q.front();
        comp[u] = c;
        q.pop();
        vis[u] = 1;
        for (auto& [v, w, idx] : adj[u]) {
          if (!isbr[idx] && !vis[v]) {
            q.push(v);
            vis[v] = 1;
          }
        }
      }
    }
  }
  map<int, vector<int>> cmp;
  for (int x : nodes) {
    cmp[comp[x]].push_back(x);
  }
  int root = -1;
  for (auto [x, y] : cmp) {
    if (y.size() == 1) {
      root = y[0];
      break;
    }
  }
  vector<vector<array<int, 2>>> adj2(101);
  queue<int> q;
  q.push(root);
  vis = vector<bool>(N);
  int ord = 0;
  map<int, int> comp_ord;
  map<int, int> art_ord;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (auto& [v, w, idx] : adj[u]) {
      if (vis[v]) continue;
      if (isbr[idx]) {
        comp_ord[comp[u]] = ++ord;
        art_ord[u] = ord;
        comp_ord[comp[v]] = ++ord;
        art_ord[v] = ord;
        adj2[comp[u]].push_back({comp[v], w});
        adj2[comp[v]].push_back({comp[u], w});
      }
      q.push(v);
      vis[v] = 1;
    }
  }
  for (auto& [x, v] : cmp) {
    if (v.size() == 2) {
      if (art_ord[v[0]] > art_ord[v[1]]) {
        swap(v[0], v[1]);
      }
    }
  }
  vector<array<int, 2>> repdis(N, array<int, 2>({1ll << 61, 1ll << 61}));
  auto f = [&](int node, int wh) {
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    pq.push({0, node});
    while (pq.size()) {
      auto [dis, u] = pq.top();
      pq.pop();
      if (repdis[u][wh] <= dis) continue;
      repdis[u][wh] = dis;
      for (auto& [v, w, idx] : adj[u]) {
        if (repdis[v][wh] <= dis + w || isbr[idx]) continue;
        pq.push({dis + w, v});
      }
    }
    repdis[node][wh] = 0;
  };
  for (auto [x, v] : cmp) {
    for (int i = 0; i < v.size(); ++i) {
      f(v[i], i);
    }
  }
  vector<vector<int>> c_dis(101, vector<int>(101));
  for (int i = 0; i <= c; ++i) {
    queue<array<int, 2>> q;
    q.push({i, 0});
    vis = vector<bool>(101);
    while (q.size()) {
      auto [u, add] = q.front();
      q.pop();
      vis[u] = 1;
      for (auto& [v, w] : adj2[u]) {
        if (vis[v]) continue;
        c_dis[i][v] = c_dis[i][u] + w + add;
        int a = 0;
        if (cmp[v].size() == 2) {
          a += max(repdis[cmp[v][1]][0], repdis[cmp[v][1]][1]);
        }
        q.push({v, a});
      }
    }
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    int cu = comp[u], cv = comp[v];
    assert(cu ^ cv);
    int ans = c_dis[cu][cv];
    assert(c_dis[cu][cv] == c_dis[cv][cu]);
    if (comp_ord[cu] > comp_ord[cv]) {
      ans += repdis[u][0];
      if (repdis[v][1] == 1ll << 61) {
        ans += repdis[v][0];
      } else {
        ans += repdis[v][1];
      }
    } else {
      ans += repdis[v][0];
      if (repdis[u][1] == 1ll << 61) {
        ans += repdis[u][0];
      } else {
        ans += repdis[u][1];
      }
    }
    cout << ans << '\n';
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