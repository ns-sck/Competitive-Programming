#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;

#define lch (i << 1)
#define rch (i << 1 | 1)

struct Info {
  int sum;
  vector<bool> cnt;

  Info() : sum(0) {
    cnt.resize(41);
  }
  Info(int x) : sum(1) {
    cnt.resize(41);
    cnt[x] = 1;
  }

  Info unite(const Info& b) {
    Info res;
    for (int i = 1; i <= 40; ++i) {
      res.cnt[i] = cnt[i] || b.cnt[i];
      res.sum += res.cnt[i];
    }
    return res;
  }

  // friend ostream& operator<<(ostream& os, const Info& info) {
  //   os << "sum: " << info.sum << ", min: " << info.mn << ", max: " << info.mx;
  //   return os;
  // }
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
    for (int i = 1; i <= 40; ++i) {
      a.cnt[i] = 0;
    }
    a.cnt[val] = 1;
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

  // int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
  //   if (nr == -1) nr = n - 1;
  //   if (nr < ql || nl > qr || info[i].mx < x) {
  //     return -1;
  //   }
  //   if (nl == nr) {
  //     return nr;
  //   } 
  //   int m = (nl + nr) >> 1;
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
  SimpleSegmentTree st(info);
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
      st.modify(i - 1, x);
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