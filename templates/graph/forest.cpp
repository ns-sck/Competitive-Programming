template <typename T>
class forest : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::adj;
  using graph<T>::n;

  forest(int _n) : graph<T>(_n) {
  }

  int add(int u, int v, T cost = 1) {
    assert(0 <= u && u < n && 0 <= v && v < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    adj[u].push_back(id);
    adj[v].push_back(id);
    edges.push_back({u, v, cost});
    return id;
  }
};