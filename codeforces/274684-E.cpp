#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;

#define lch (i << 1)
#define rch (i << 1 | 1)

struct Info {
  pair<int, int> mn;

  Info() {
    mn = {INF, -1};
  }
  // Info(int x) : sum(x), mn(x), mx(x) {}

  Info unite(const Info& b) {
    Info res;
    if (mn <= b.mn) {
      res.mn = mn;
    } else {
      res.mn = b.mn;
    }
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

  void apply(Info& a, int val, int i) {
    a.mn = {val, i};
  }

  void modify(int i, int val) {
    i += n;
    apply(info[i], val, i - n);
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
  vector<int> arr(N, INF);
  vector<Info> info(N);
  SimpleSegmentTree st(info);
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int p, x;
      cin >> p >> x;
      st.modify(p, x);
      arr[p] = x;
    } else {
      int l, r, h;
      cin >> l >> r >> h;
      int ans = 0;
      while (1) {
        Info inf = st.query(l, r - 1);
        if (inf.mn.first <= h) {
          st.modify(inf.mn.second, INF);
          ++ans;
        } else {
          break;
        }
      }
      cout << ans << '\n';
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