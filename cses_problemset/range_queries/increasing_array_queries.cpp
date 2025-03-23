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
  Info(int i, int x) : sum(x), mn(x), mx(x), idx(i) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    res.mn = min(mn, b.mn);
    res.mx = max(mx, b.mx);
    res.idx = mx > b.mx ? idx : b.idx;
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
  int N, Q;
  cin >> N >> Q;
  vector<int> arr(N + 1);
  vector<Info> info(N + 1);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    info[i] = {i, arr[i]};
  }
  arr[N] = 1e12;
  info[N] = {N, arr[N]};
  SimpleSegmentTree st(info);
  vector<int> need(N + 1);
  int last = N, add = 0;
  for (int i = N - 1; ~i; --i) {
    int r = st.bs(i + 1, N, arr[i]);
    if (r > i) {
      need[i] += need[r];
    }
    if (r > i + 1) {
      need[i] += arr[i] * (r - i - 1) - st.query(i + 1, r - 1).sum;
    }
  }
  while (Q--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    int r = st.query(i, j).idx;
    int ans = need[i] - need[r];
    ans += arr[r] * (j - r + 1) - st.query(r, j).sum;
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