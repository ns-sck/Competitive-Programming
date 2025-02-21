#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;

#define lch (i << 1)
#define rch (i << 1 | 1)

struct Info {
  int sum;
  vector<int> cnt;

  Info() : sum(0) {
    cnt.resize(41);
  }
  Info(int x) : sum(0) {
    cnt.resize(41);
    cnt[x] = 1;
  }

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    int c = 0;
    for (int i = 1; i <= 40; ++i) {
      res.cnt[i] = cnt[i] + b.cnt[i];
      c += b.cnt[i - 1];
      res.sum += cnt[i] * c;
    }
    return res;
  }

  // friend ostream& operator<<(ostream& os, const Info& info) {
  //   os << "sum: " << info.sum << ", min: " << info.mn << ", max: " << info.mx;
  //   return os;
  // }
};

struct Tag {
  int put = -1;
  Tag() : put(-1) {}

  void apply(Info& a, int nl, int nr) {
    if (put != -1) {
      // a.sum = (nr - nl + 1) * put;
      for (int i = 0; i < 41; ++i) {
        a.cnt[i] = 0;
      }
      a.cnt[put] = 1;
      // a.mn = a.mx = put;
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
  
  // int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
  //   if (nr == -1) nr = n - 1;
  //   if (nr < ql || nl > qr || info[i].mx < x) {
  //     return -1;
  //   }
  //   if (nl == nr) {
  //     return nr;
  //   } 
  //   push(i, nl, nr);
  //   int m = (nl + nr) / 2;
  //   int res = bs(ql, qr, x, lch, nl, m);
  //   if (res != -1) {
  //     return res;
  //   }
  //   return bs(ql, qr, x, rch, m + 1, nr);
  // }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    info[i] = x;
  }
  LazySegmentTree st(info);
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << st.query(l, r).sum << '\n';
    } else {
      int i, x;
      cin >> i >> x;
      st.modify(i - 1, i - 1, x);
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