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

  friend ostream& operator<<(ostream& os, const Info& info) {
    os << "sum: " << info.sum << ", min: " << info.mn << ", max: " << info.mx;
    return os;
  }
};

struct Tag {
  int put = -2;
  Tag() : put(-2) {}

  void apply(Info& a, int nl, int nr) {
    if (put != -2) {
      a.sum = (nr - nl + 1) * put;
      a.mx = max(a.mx, put);
      if (put == -1) {
        a.mx = -1;
      }
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
    if (tag[i].put != -2) {
      tag[i].apply(info[i], nl, nr);
      if (nl ^ nr) {
        tag[lch].put = max(tag[lch].put, tag[i].put);
        tag[rch].put = max(tag[rch].put, tag[i].put);
      }
      tag[i].put = -2;
    }
  }

  void modify(int ql, int qr, int val, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
      tag[i].put = val;
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
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    info[i] = -1;
  }
  LazySegmentTree st(info);
  int Q;
  cin >> Q;
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int p, x;
      cin >> p >> x;
      --p;
      st.modify(p, p, -1);
      arr[p] = x;
    } else {
      int x;
      cin >> x;
      st.modify(0, N - 1, x);
    }
  }
  for (int i = 0; i < N; ++i) {
    arr[i] = max(arr[i], st.query(i, i).mx);
    cout << arr[i] << " \n"[i == N - 1];
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