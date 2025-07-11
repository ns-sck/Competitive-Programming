#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
constexpr int INF = 1ll << 61;
 
#define lch (i << 1)
#define rch (i << 1 | 1)
 
struct Info {
  int pref;
  int suff;
  int mx;
  int sum;
  int st;
 
  Info() : pref(0), suff(0), mx(0), sum(0) {}
  Info(int x) : pref(x), suff(x), mx(x), sum(x) {}
 
  Info unite(const Info& b) {
    Info res;
    
    res.pref = max(pref, sum + b.pref);
    res.suff = max(b.suff, suff + b.sum);
    res.mx = max({mx, b.mx, suff + b.pref});
    res.sum = sum + b.sum;
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
    a.pref += val;
    a.suff += val;
    a.mx += val;
    a.sum += val;
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
        res = info[l++].unite(res);
      }
      if (~r & 1) {
        res = info[r--].unite(res);
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
  SimpleSegmentTree st(info);
  while (Q--) {
    int i, x;
    cin >> i >> x;
    --i;
    st.modify(i, x - arr[i]);
    arr[i] = x;
    cout << st.query(0, N - 1).mx << '\n';
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