#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> adj;
  int n;

  graph(int _n) : n(_n) {
    adj.resize(n);
  }

  virtual int add(int u, int v, T cost) = 0;
};

template <typename T>
class digraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::adj;
  using graph<T>::n;

  digraph(int _n) : graph<T>(_n) {
  }

  int add(int u, int v, T cost = 1) {
    assert(0 <= u && u < n && 0 <= v && v < n);
    int id = (int) edges.size();
    adj[u].push_back(id);
    edges.push_back({u, v, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    return rev;
  }

  vector<int> cysz;
  vector<int> vis;
  vector<int> act;
  vector<int> cypr;

  void cycle() {
    cysz.assign(n, -1);
    vis.assign(n, 0);
    act.assign(n, 0);
    cypr.assign(n, -1);
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        dfs_cycle(i);
      }
    }
  }

  void dfs_cycle(int u) {
    vis[u] = 1;
    act[u] = 1;
    for (int& eid : adj[u]) {
      int v = edges[eid].from ^ edges[eid].to ^ u;
      if (act[v]) {
        vector<int> group = {u};
        cypr[v] = u;
        int x = cypr[u];
        while (x != u) {
          group.push_back(x);
          x = cypr[x];
        }
        for (int& a : group) {
          cysz[a] = group.size();
        }
      } else if (!vis[v]) {
        cypr[v] = u;
        dfs_cycle(v);
      }
    }
    act[u] = 0;
  }
};

void solve() {
  int N;
  cin >> N;
  digraph<int> g(N);
  for (int i = 0; i < N; ++i) {
    int j;
    cin >> j;
    g.add(i, j - 1);
  }
  g.cycle();
  digraph<int> g2 = g.reverse();
  queue<int> q;
  vector<int> ans(N);
  for (int i = 0; i < N; ++i) {
    if (g.cysz[i] != -1) {
      ans[i] = g.cysz[i];
      for (int& eid : g2.adj[i]) {
        int v = g2.edges[eid].from ^ g2.edges[eid].to ^ i;
        if (g.cysz[v] == -1) {
          ans[v] = g.cysz[i] + 1;
          q.push(v);
        }
      }
    }
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int& eid : g2.adj[u]) {
      int v = g2.edges[eid].from ^ g2.edges[eid].to ^ u;
      if (g.cysz[v] == -1) {
        ans[v] = ans[u] + 1;
        q.push(v);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << ans[i] << " \n"[i == N - 1];
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