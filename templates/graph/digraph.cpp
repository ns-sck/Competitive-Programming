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
      rev.add(e.v, e.u, e.cost);
    }
    return rev;
  }
};