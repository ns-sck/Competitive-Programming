#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class dsu_r {
 public:
  vector<int> p;
  vector<int> sz;
  vector<array<int, 2>> st;
  vector<int> csz;
  int n;
  int comp;
  int cur;

  dsu_r(int _n) : n(_n) {
    comp = _n;
    cur = -1;
    p.resize(n);
    sz.resize(n);
    csz.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (sz[x] < sz[y]) swap(x, y);
    if (x != y) {
      p[y] = x;
      sz[x] += sz[y];
      st.push_back({y, x});
      csz[++cur] = comp--;  
      return true;
    }
    return false;
  }

  void rollback(int i) {
    while (cur > i) {
      int x = st[cur][1], y = st[cur][0];
      p[y] = y;
      sz[x] -= sz[y];
      comp = csz[cur];
      cur--;
      st.pop_back();
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

  LazySegmentTree(vector<Info>& a) : n(1 << (32 - __builtin_clz(a.size() - 1))) {
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
  int N, M, Q;
  cin >> N >> M >> Q;
  dsu_r d(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d.unite(u, v);
  }
  Q <<= 1;
  map<pair<int, int>, int> mp;
  vector<Info> info(Q);
  LazySegmentTree st(info);
  vector<int> qrs = {0};
  for (int i = 0; i < Q; i += 2) {
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
      st.modify(j, i, 1);
      mp.erase({a, b});
    }
    qrs.push_back(i + 1);
  }
  for (auto [x, y] : mp) {
    a = x.first, b = x.second;
    st.modify(y, Q, 1);
  }
  int j = 0, sz = st.n << 1;
  qrs.push_back(1 << 30);
  auto dfs = [&](auto&& self, int i, int l, int r) -> void {
    // cout << i << '\n';
    if (l >= r) {
      if (j < qrs.size() && qrs[j] == l) {
        cout << d.comp << ' ';
        j++;
      }
      return;
    }
    int prev = d.cur;
    for (auto [x, y] : st.tag[i].stc) {
      if (d.unite(x, y)) {
      }
    }
    int mid = (l + r) >> 1;
    self(self, lch, l, mid);
    self(self, rch, mid + 1, r);
    d.rollback(prev);
  };
  dfs(dfs, 1, 0, sz / 2 - 1);
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