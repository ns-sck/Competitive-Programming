#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;

#define lch i << 1
#define rch i << 1 | 1

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

  friend ostream& operator<<(ostream& os, const Info& info) {
    os << "sum: " << info.sum << ", min: " << info.mn << ", max: " << info.mx;
    return os;
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
      if (l & 1) res = res.unite(info[l++]);
      if (~r & 1) res = res.unite(info[r--]); 
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
  vector<Info> odd(N), even(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    if (i & 1) {
      odd[i] = arr[i];
    } else {
      even[i] = arr[i];
    }
  }
  SimpleSegmentTree ste(even), sto(odd);
  int Q;
  cin >> Q;
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int ans = ste.query(l, r).sum - sto.query(l, r).sum;
      if (l & 1) {
        ans = -ans;
      }
      cout << ans << '\n';
    } else {
      int i, j;
      cin >> i >> j;
      --i;
      if (i & 1) {
        sto.modify(i, j - arr[i]);
        arr[i] = j;
      } else {
        ste.modify(i, j - arr[i]);
        arr[i] = j;
      }
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