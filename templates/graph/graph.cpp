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