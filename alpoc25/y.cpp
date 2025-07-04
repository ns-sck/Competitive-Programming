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
  int idx;

  Info() : sum(0), mn(INF), mx(-INF) {}
  Info(int x, int idx) : sum(x), mn(x), mx(x), idx(idx) {}

  Info unite(const Info& b) {
    Info res;
    if (mn < b.mn) {
      res.idx = idx;
    } else {
      res.idx = b.idx;
    }
    res.sum = sum + b.sum;
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
    a.sum += val;
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
    if (nr < ql || nl > qr || info[i].mx < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    }
    int m = (nl + nr) >> 1;
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
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    info[i] = {arr[i], i};
  }
  SimpleSegmentTree st(info);
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r, k;
    cin >> l >> r >> k;
    --l, --r;
    int ans = 1;
    int cnt = 0;
    auto get = [&](auto&& self, int l, int r) -> void {
      cnt++;
      if (l + k - 1 > r) return;
      int mn = st.query(l, r).idx;
      ans = max(ans, arr[mn]);
      self(self, mn + 1, r);
      self(self, l, mn - 1);
    };
    get(get, l, r);
    cout << ans << '\n';
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