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
  vector<int> arr(N);
  vector<Info> info(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    info[i] = arr[i];
  }
  vector<vector<vector<int>>> qrs(N);
  int idx = 1, time = 0;
  for (int i = 0; i < Q; ++i) {
    int qt, k, a, b;
    cin >> qt;
    if (qt == 1) {
      cin >> k >> a >> b;
      qrs[k - 1].push_back({1, a - 1, b});
    } else if (qt == 2) {
      cin >> k >> a >> b;
      qrs[k - 1].push_back({2, time++, a - 1, b - 1});
    } else {
      cin >> k;
      qrs[k - 1].push_back({3, idx++});
    }
  }
  vector<int> ans(time);
  SimpleSegmentTree st(info);
  auto dfs = [&](auto&& self, int k, int i) -> void {
    if (i == qrs[k].size()) {
      return;
    }
    int qt = qrs[k][i][0];
    if (qt == 1) {
      int l = qrs[k][i][1], x = qrs[k][i][2] - st.query(l, l).sum;
      st.modify(l, x);
      self(self, k, i + 1);
      st.modify(l, -x);
    } else if (qt == 2) {
      int l = qrs[k][i][2], r = qrs[k][i][3], t = qrs[k][i][1];
      ans[t] = st.query(l, r).sum;
      self(self, k, i + 1);
    } else {
      int m = qrs[k][i][1];
      self(self, m, 0);
      self(self, k, i + 1);
    }
  };
  dfs(dfs, 0, 0);
  for (int i = 0; i < time; ++i) {
    cout << ans[i] << '\n';
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