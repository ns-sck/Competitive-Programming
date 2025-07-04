class dsu_r {
 public:
  vector<int> p;
  vector<int> sz;
  vector<int> stk;
  int n;
  int comp;
  int cur;

  dsu_r(int _n) : n(_n) {
    comp = _n;
    p.resize(n);
    sz.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }

  inline int get(int x) { return (x == p[x] ? x : get(p[x])); }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (sz[x] < sz[y]) swap(x, y);
    if (x != y) {
      p[y] = x;
      sz[x] += sz[y];
      stk.push_back(y);
      comp--;
      return true;
    }
    return false;
  }

  void rollback(int i) {
    while (stk.size() > i) {
      int y = stk.back();
      stk.pop_back();
      sz[p[y]] -= sz[y];
      p[y] = y;
      comp++;
    }
  }
};