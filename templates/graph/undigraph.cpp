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

  int add(int u, int v, T cost = 1) {
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
};