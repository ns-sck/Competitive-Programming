#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;

#define lch (i << 1)
#define rch (i << 1 | 1)

struct Info {
  int sum;
  int mn;
  int mx;

  Info() : sum(0), mn(INF), mx(-INF) {}
  Info(int x) : sum(x), mn(x), mx(x) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    res.mn = min(mn, b.mn);
    res.mx = max(mx, b.mx);
    return res;
  }
};

struct SimpleSegmentTree {

  int n;
  vector<Info> info;
  SimpleSegmentTree(vector<Info>& a) : n(1 << (32 - __builtin_clz(a.size() - 1))) {
    info.resize(n << 1);
    for (int i = 0; i < a.size(); ++i) {
      info[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      info[i] = info[lch].unite(info[rch]);
    }
  }

  void apply(Info& a, int val) {
    a.sum += val;
    a.mn += val;
    a.mx += val;
  }

  void modify(int i, int val) {
    i += n;
    apply(info[i], val);
    i >>= 1;
    while (i >= 1) {
      info[i] = info[lch].unite(info[rch]);
      i >>= 1;
    }
  }

  Info query(int l, int r) {
    l += n;
    r += n;
    Info res;
    while (l <= r) {
      if (l & 1) {
        res = res.unite(info[l++]);
      }
      if (~r & 1) {
        res = res.unite(info[r--]);
      }
      l >>= 1, r >>= 1;
    }
    return res;
  }

  int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    if (nr < ql || nl > qr || info[i].mx < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    }
    int m = (nl + nr) >> 1;
    int res = bs(ql, qr, x, lch, nl, m);
    if (res != -1) {
      return res;
    }
    return bs(ql, qr, x, rch, m + 1, nr);
  }
};

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

  vector<int> prh, depth, heavy, head, pos;
  int t;

  int hld_dfs(int u) {
    int size = 1;
    int mx = 0;
    for (int& eid : adj[u]) {
      int v = edges[eid].from ^ edges[eid].to ^ u;
      if (v != prh[u]) {
        prh[v] = u;
        depth[v] = depth[u] + 1;
        int c = hld_dfs(v);
        size += c;
        if (c > mx) {
          mx = c, heavy[u] = v;
        }
      }
    }
    return size;
  }

  void decompose(int u, int h) {
    head[u] = h, pos[u] = t++;
    if (heavy[u] != -1) {
      decompose(heavy[u], h);
      for (int& eid : adj[u]) {
        int v = edges[eid].from ^ edges[eid].to ^ u;
        if (v != prh[u] && v != heavy[u]) {
          decompose(v, v);
        }
      }
    }
  }

  void hld() {
    prh = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    t = 0;
    hld_dfs(0);
    decompose(0, 0);
  }
  
  int query(int a, int b, SimpleSegmentTree& st) {
    int res = 0;
    for (; head[a] != head[b]; b = prh[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) {
        swap(a, b);
      }
      int cur_mx = st.query(pos[head[b]], pos[b]).mx;
      res = max(res, cur_mx);
    }
    if (depth[a] > depth[b]) {
      swap(a, b);
    }
    int last_mx = st.query(pos[a], pos[b]).mx;
    res = max(res, last_mx);
    return res;
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  undigraph<int> g(N);
  vector<int> arr(N);
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];    
  }
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  g.hld();
  for (int i = 0; i < N; ++i) {
    info[g.pos[i]] = {arr[i]};
  }
  SimpleSegmentTree st(info);
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int i, x;
      cin >> i >> x;
      --i;
      st.modify(g.pos[i], x - arr[i]);
      arr[i] = x;
    } else {
      int a, b;
      cin >> a >> b;
      --a, --b;
      cout << g.query(a, b, st) << " \n"[Q == 1];
    }
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