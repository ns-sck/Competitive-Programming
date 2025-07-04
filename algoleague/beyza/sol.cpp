#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;

#define lch (i << 1)
#define rch (i << 1 | 1)

struct Info {
  int g;
  int mn;
  int mx;

  Info() : g(0), mn(INF), mx(-INF) {}
  Info(int x) : g(x), mn(x), mx(x) {}

  Info unite(const Info& b) {
    Info res;
    res.g = __gcd(g, b.g);
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
    a.g += val;
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
    if (nr < ql || nl > qr || info[i].g % x == 0) {
      return -2;
    }
    if (nl == nr) {
      return nr;
    }
    int m = (nl + nr) >> 1;
    int res = bs(ql, qr, x, lch, nl, m);
    if (res != -2) {
      return res;
    }
    return bs(ql, qr, x, rch, m + 1, nr);
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  assert(1 <= N <= 1e5);
  assert(1 <= Q <= 1e5);
  vector<int> arr(N);
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    assert(1 <= arr[i] <= 1e9);
    info[i] = arr[i];
  }
  SimpleSegmentTree st(info);
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt & 1) {
      int i, x;
      assert(1 <= i <= N);
      assert(1 <= x <= 1e9);
      cin >> i >> x;
      --i;
      st.modify(i, x - arr[i]);
      arr[i] = x;
    } else {
      int d;
      cin >> d;
      assert(1 <= d <= 1e9);
      cout << st.bs(0, N - 1, d) + 1 << '\n';
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