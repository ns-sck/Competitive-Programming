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
class undigraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::adj;
  using graph<T>::n;

  int time;
  int h;
  vector<int> sz;
  vector<int> par;
  vector<int> dep;
  vector<int> in;
  vector<int> out;
  vector<vector<int>> pr;

  undigraph(int _n) : graph<T>(_n) { 
  }

  int add(int u, int v, T cost = 1) override { 
    assert(0 <= u && u < n && 0 <= v && v < n);
    int id = (int) edges.size();
    adj[u].push_back(id);
    adj[v].push_back(id);
    edges.push_back({u, v, cost});
    return id;
  }

  void init() {
    sz = vector<int>(n, 0);
    par = vector<int>(n, -1);
    dep = vector<int>(n, 0);
    in = vector<int>(n,-1);
    out = vector<int>(n, -1);
    time = 0;
    h = 1;
  }

  void init_dfs(int u, int p) {
    in[u] = time++;
    sz[u] = 1;
    if (adj[u].size() == 1 && p != -1) {
      return;
    }
    for (int& id : adj[u]) {
      auto [from, to, c] = edges[id];
      int v = from ^ to ^ u;
      if (v == p) continue;
      dep[v] = dep[u] + 1;
      par[v] = u;
      sz[u] += sz[v];
      init_dfs(v, u);
    }
    out[u] = time++;
  }  

  int centroid_decomposition(int k) {
    vector<bool> alive(n, true);
    vector<int> csz(n);
    int ans = 0;
    auto Dfs = [&](auto&& self, int u, int p) -> void {
      csz[u] = 1;
      for (int& eid : adj[u]) {
        auto& e = edges[eid];
        int v = e.from ^ e.to ^ u;
        if (v != p && alive[v]) {
          self(self, v, u);
          csz[u] += csz[v];
        }
      }
    };
    // ----------------
    int mx = 0;
    vector<int> cnt(k + 1);
    vector<int> temp(k + 1);
    cnt[0] = 1;
    temp[0] = 1;
    auto calc = [&](auto&& self, int u, int p, int d) -> void {
      if (d > k) {
        return;
      }
      mx = max(mx, d);
      cnt[d]++;
      ans += temp[k - d];
      for (int& eid : adj[u]) {
        auto& e = edges[eid];
        int v = e.from ^ e.to ^ u;
        if (v != p && alive[v]) {
          self(self, v, u, d + 1);
        }
      }
      temp[d]++;
    };
    // ----------------
    auto Build = [&](auto&& self, int u, int pc) -> void {
      mx = 0;
      Dfs(Dfs, u, -1);
      int c = u;
      int p = -1;
      while (true) {
        int nxt = -1;
        for (int eid : adj[c]) {
          auto& e = edges[eid];
          int v = e.from ^ e.to ^ c;
          if (v != p && alive[v] && 2 * csz[v] > csz[u]) {
            nxt = v;
            break;
          }
        }
        if (nxt == -1) break;
        p = c;
        c = nxt;
      }
      alive[c] = false;
      for (int eid : adj[c]) {
        auto& e = edges[eid];
        int v = e.from ^ e.to ^ c;
        if (alive[v]) {
          calc(calc, v, c, 1);
        }
      }
      fill(cnt.begin() + 1, cnt.begin() + mx + 1, 0);
      fill(temp.begin() + 1, temp.begin() + mx + 1, 0);
      for (int eid : adj[c]) {
        auto& e = edges[eid];
        int v = e.from ^ e.to ^ c;
        if (alive[v]) {
          self(self, v, c);
        }
      }
    };

    for (int i = 0; i < n; i++) {
      if (alive[i]) {
        Build(Build, i, -1);
      }
    }
    return ans;
  }
};

// the solution gets TLE for two testcases
// maybe using static arrays solves the problem?
void solve() {
  int N, K;
  cin >> N >> K;
  undigraph<int> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  cout << g.centroid_decomposition(K) << '\n';
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