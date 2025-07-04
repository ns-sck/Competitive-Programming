#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

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

constexpr int INF = 1ll << 61;

#define lch (i << 1)
#define rch (i << 1 | 1)

int a, b, c;

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

struct Tag {
  int put = -1;
  vector<pair<int, int>> stc = {};
  Tag() : put(-1) {}

  void apply(Info& a, int nl, int nr) {
    if (put != -1) {
      a.sum = (nr - nl + 1) * put;
      a.mn = a.mx = put;
    }
  }
};

struct LazySegmentTree {
  int n;
  vector<Info> info;
  vector<Tag> tag;

  LazySegmentTree(vector<Info>& a)
      : n(1 << (32 - __builtin_clz(a.size() - 1))) {
    info.resize(n << 1);
    tag.resize(n << 1);
    for (int i = 0; i < a.size(); ++i) {
      info[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      info[i] = info[lch].unite(info[rch]);
    }
  }

  void push(int i, int nl, int nr) {
    if (tag[i].put != -1) {
      tag[i].apply(info[i], nl, nr);
      if (nl ^ nr) {
        tag[lch].put = tag[rch].put = tag[i].put;
      }
      tag[i].put = -1;
    }
  }

  void modify(int ql, int qr, int val, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
      tag[i].put = val;
      tag[i].stc.push_back({a, b});
      push(i, nl, nr);
      return;
    }

    int mid = (nl + nr) / 2;
    modify(ql, qr, val, lch, nl, mid);
    modify(ql, qr, val, rch, mid + 1, nr);

    info[i] = info[lch].unite(info[rch]);
  }

  Info query(int ql, int qr, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) {
      return Info();
    }
    if (nl >= ql && nr <= qr) {
      return info[i];
    }

    int mid = (nl + nr) >> 1;
    Info a = query(ql, qr, lch, nl, mid);
    Info b = query(ql, qr, rch, mid + 1, nr);

    return a.unite(b);
  }

  int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    if (nr < ql || nl > qr || info[i].mx < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    }
    push(i, nl, nr);
    int m = (nl + nr) / 2;
    int res = bs(ql, qr, x, lch, nl, m);
    if (res != -1) {
      return res;
    }
    return bs(ql, qr, x, rch, m + 1, nr);
  }
};

void solve() {
  // NOOOO PATTTTTHHH COMMMPRESSION, OK?
  int N, M, Q;
  cin >> N >> M >> Q;
  dsu_r d(N);
  map<pair<int, int>, int> mp;
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v) swap(u, v);
    mp[{u, v}] = 0;
  }
  vector<Info> info(Q + 1);
  LazySegmentTree st(info);
  for (int i = 1; i <= Q; ++i) {
    int qt;
    cin >> qt >> a >> b;
    --a, --b;
    if (a > b) swap(a, b);
    if (qt & 1) {
      if (!mp.count({a, b})) {
        mp[{a, b}] = i;
      }
    } else {
      int j = mp[{a, b}];
      debug(a, b);
      st.modify(j, i - 1, 1);
      mp.erase({a, b});
    }
  }
  for (auto [x, y] : mp) {
    a = x.first, b = x.second;
    st.modify(y, st.n - 1, 1);
  }
  int j = 0, sz = st.n << 1;
  vector<int> ans(Q + 1);
  auto dfs = [&](auto&& self, int i, int l, int r) -> void {
    int prev = d.stk.size();
    for (auto [x, y] : st.tag[i].stc) {
      d.unite(x, y);
    }
    if (l == r) {
      if (l <= Q) {
        ans[l] = d.comp;
      }
    } else {
      int mid = (l + r) >> 1;
      self(self, lch, l, mid);
      self(self, rch, mid + 1, r);
    }
    d.rollback(prev);
  };
  dfs(dfs, 1, 0, st.n - 1);
  for (int i = 0; i <= Q; ++i) {
    cout << ans[i] << " \n"[i == Q];
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