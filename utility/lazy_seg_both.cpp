#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int INF = 1ll << 61;

#define lch i << 1
#define rch i << 1 | 1

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

  friend ostream& operator<<(ostream& os, const Info& info) {
    os << "Sum: " << info.sum << ", Min: " << info.mn << ", Max: " << info.mx;
    return os;
  }
};

struct Tag {
  int delta = 0;
  int put = -1;
  Tag() : put(-1), delta(0) {}
  void apply(Info& a, int nl, int nr) {
    if (put != -1) {
      a.sum = (nr - nl + 1) * put;
      a.mn = a.mx = put;
      delta = 0;
    }
    a.sum += (delta * (nr - nl + 1));
    a.mn += delta;
    a.mx += delta;
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
        tag[lch].delta = tag[rch].delta = 0;
      }
      tag[i].put = -1;
    }
    if (tag[i].delta) {
      tag[i].apply(info[i], nl, nr);
      if (nl ^ nr) {
        tag[lch].delta += tag[i].delta;
        tag[rch].delta += tag[i].delta;
      }
      tag[i].delta = 0;
    }
  }

  void put(int ql, int qr, int val, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
      tag[i].put = val;
      tag[i].delta = 0;
      push(i, nl, nr);
      return;
    }

    int mid = (nl + nr) / 2;
    put(ql, qr, val, lch, nl, mid);
    put(ql, qr, val, rch, mid + 1, nr);

    info[i] = info[lch].unite(info[rch]);
  }

  void add(int ql, int qr, int val, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
      tag[i].delta += val;
      push(i, nl, nr);
      return;
    }

    int mid = (nl + nr) / 2;
    add(ql, qr, val, lch, nl, mid);
    add(ql, qr, val, rch, mid + 1, nr);

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
  int N, Q;
  cin >> N >> Q;
  vector<Info> info(N);
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    info[i] = Info(arr[i]);
  }
  LazySegmentTree st(info);
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int k, u;
      cin >> k >> u;
      --k;
      st.put(k, k, u);
      arr[k] = u;
    } else if (qt == 2) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << st.query(l, r).sum << '\n';
    }
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
