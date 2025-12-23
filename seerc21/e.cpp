#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

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
    a.sum = val;
    a.mn = val;
    a.mx = val;
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
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  a.push_back(1ll << 61);
  for (int i = 0; i < M; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  set<array<int, 2>> s;
  vector<int> dp(N + 1, 1);
  vector<Info> info(N + M + 5);
  vector<int> d(N + 1);
  for (int i = 0; i < N + M + 1; ++i) {
    if (i <= N) {
      d[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - i;
    }
    info[i] = -(1 << 30);
  }
  debug(d);
  SimpleSegmentTree st(info);
  // u - v - 1 <= pu - pv
  // pv - v - 1 <= pu - u
  dp[0] = 1;
  st.modify(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    dp[i] = st.query(0, d[i] + 1 + N).mx + 1;
    if (i) {
      if (a[i] > a[i - 1]) dp[i] = max(dp[i], dp[i - 1] + 1);
      int old = st.query(d[i - 1] + N, d[i - 1] + N).mx;
      st.modify(d[i - 1] + N, max(old, dp[i - 1]));
    }
  }
  debug(dp);
  int ans = N + 1 - dp[N];
  if (ans > M) cout << -1 << '\n';
  else cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}