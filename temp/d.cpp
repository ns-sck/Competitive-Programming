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
  int N, K;
  cin >> N >> K;
  // N = 11, K = 3;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  // for (int i = 0; i < 8; ++i) {
  //   arr[i] = rand() % 31;
  // }
  vector<int> dp(N);
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    info[i] = 0;
  }
  SimpleSegmentTree st(info);
  for (int i = N - 1 - K; ~i; --i) {
    int lo = 1, hi = N / 2, can = 1;
    while (lo <= hi) {
      int mi = (lo + hi) >> 1;
      int empty = N - i - 1 - mi + 1;
      if (empty / K >= mi) {
        can = mi;
        lo = mi + 1;
      } else {
        hi = mi - 1;
      }
    }
    int best = st.query(0, can - 1).mx;
    int old = st.query(can, can).mx;
    st.modify(can, max(arr[i] + best, old));
    if (can > 1) {
      int best2 = st.query(0, can - 2).mx;
      int old2 = st.query(0, can - 1).mx;
      st.modify(can - 1, max(arr[i] + best, old));
    }
  }
  int ans = st.query(0, N - 1).mx;
  // auto dfs = [&](auto&& self, int i, int r, int t) {
  //   if (i == N) {
  //     if (r > 0) t = 0;
  //     return t;
  //   }
  //   int a = self(self, i + 1, max((int) 0, r - 1), t);
  //   a = max(a, self(self, i + 1, r + K, t + arr[i]));
  // };
  // int ans3 = dfs(dfs, 0, 0, 0);
  // cout << ans3 << ' ';
  cout << ans << '\n';
  // if (ans3 != ans) {
  //   for (int i = 0; i < N; ++i) {
  //     cout << arr[i] << " \n"[i == N - 1];
  //   }
  // }
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}