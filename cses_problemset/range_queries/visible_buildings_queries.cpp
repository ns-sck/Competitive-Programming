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
    if (nr < ql || nl > qr || info[i].sum < 1) {
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
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    mp[arr[i]] = 1;
  }
  int c = 0;
  for (auto& [x, y] : mp) {
    y = c++;
  }
  for (int i = 0; i < N; ++i) {
    arr[i] = mp[arr[i]];
  }
  vector<Info> info(N + 1);
  for (int i = 0; i < N; ++i) {
    info[i] = N;
  }
  SimpleSegmentTree st(info);
  vector<vector<int>> par(N, vector<int>(20, INF));
  debug(arr);
  for (int i = N - 1; ~i; --i) {
    int idx = st.query(arr[i] + 1, N).mn;
    debug(idx);
    if (idx != -1) {
      par[i][0] = idx;
    }
    st.modify(arr[i], i);
    debug(st.query(arr[i], arr[i]).mn);
  }
  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j < N; ++j) {
      if (par[j][i - 1] >= N) continue;
      par[j][i] = par[par[j][i - 1]][i - 1];
    }
  }
  debug(par);
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int ans = 1;
    for (int j = 19; ~j; --j) {
      if (par[l][j] <= r) {
        ans += 1 << j;
        l = par[l][j];
      }
    }
    cout << ans << '\n';
  }
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}