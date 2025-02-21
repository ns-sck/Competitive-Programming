#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;

#define lch (i << 1)
#define rch (i << 1 | 1)

struct Info {
  int rng;
  int sum;

  Info() : sum(0), rng(0) {}
  Info(int x) : sum(x), rng(1) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    res.rng = rng + b.rng;
    return res;
  }
};

struct Tag {
  int delta = 0;
  int put = -1;
  Tag() : put(-1), delta(0) {}

  void apply(Info& a, int nl, int nr) {
    a.sum = a.rng - a.sum;
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
    if (tag[i].delta == 0) return;
    tag[i].apply(info[i], nl, nr);
    if (nl ^ nr) {
      tag[lch].delta = 1 - tag[lch].delta;
      tag[rch].delta = 1 - tag[rch].delta;
    }
    tag[i].delta = 0;
  }

  void modify(int ql, int qr, int val, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
      tag[i].delta = 1 - tag[i].delta;
      push(i, nl, nr);
      return;
    }

    int mid = (nl + nr) / 2;
    modify(ql, qr, val, lch, nl, mid);
    modify(ql, qr, val, rch, mid+1, nr);

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
    push(i, nl, nr);
    if (nr < ql || nl > qr || info[i].sum < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    } 
    int m = (nl + nr) / 2;
    int res = bs(ql, qr, x, lch, nl, m);
    if (res != -1) {
      return res;
    }
    return bs(ql, qr, x - info[lch].sum, rch, m + 1, nr);
  }
};

void solve() {  
  int N, Q;
  cin >> N >> Q;
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    info[i] = 0;
  }
  LazySegmentTree st(info);
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int l, r;
      cin >> l >> r;
      st.modify(l, r - 1, 1);
    } else {
      int k;
      cin >> k;
      cout << st.bs(0, N - 1, k + 1) << '\n';
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