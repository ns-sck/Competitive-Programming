#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lch i << 1
#define rch i << 1 | 1

constexpr int INF = 1ll << 61;

struct Info {
  int ans;
  int sum;
  int pref;
  int suf;

  Info() : ans(0), pref(0), suf(0), sum(0) {}
  Info(int x) : ans(max(x, 0ll)), pref(max(x, 0ll)), suf(max(x, 0ll)), sum(x) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    res.pref = max(pref, sum + b.pref);
    res.suf = max(suf + b.sum, b.suf);
    res.ans = max({ans, b.ans, res.pref, res.suf, suf + b.pref});
    return res;
  }

  friend ostream& operator<<(ostream& os, const Info& info) {
    os << "ans: " << info.ans << ", min: " << info.pref << ", max: " << info.suf;
    return os;
  }
};

struct Tag {
  int delta = 0;
  int put = -INF;
  Tag() : put(-INF), delta(0) {}
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

  void apply(int i, int nl, int nr) {
    if (tag[i].put != -INF) {
      info[i].ans = max(0ll, tag[i].put);
      info[i].sum = tag[i].put;
      info[i].pref = max(0ll, tag[i].put);
      info[i].suf = max(0ll, tag[i].put);
      tag[i].put = -INF;
    }
  }

  void push(int i, int nl, int nr) {
    if (tag[i].put != -INF) {
      apply(i, nl, nr);
      if (nl ^ nr) {
        tag[lch].put = tag[rch].put = tag[i].put;
        tag[lch].delta = tag[rch].delta = 0;
      }
    }
    if (tag[i].delta) {
      apply(i, nl, nr);
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
  Info in = st.query(0, N - 1);
  cout << in.ans << '\n';
  while (Q--) {
    int i, x;
    cin >> i >> x;    
    st.put(i, i, x);
    in = st.query(0, N - 1);
    cout << in.ans << '\n';
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
