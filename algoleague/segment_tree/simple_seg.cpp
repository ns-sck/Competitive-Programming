#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

struct node {
  int mn, mx, sum, xr;
  int lazy = 0;

  node() {
    mx = -(1ll << 61);
    mn = 1ll << 61;
    xr = 0;
    sum = 0;
  }

  node(int x) {
    mn = mx = sum = xr = x;
    lazy = 0;
  }

  node combine(node other) {
    node res;
    res.mn = min(mn, other.mn);
    res.mx = max(mx, other.mx);
    res.xr = xr ^ other.xr;
    res.sum = sum + other.sum;
    return res;
  }

  void apply(int l, int r, int val) {
  if (val == 0) return;
    sum = (r - l + 1) - sum;
    lazy ^= 1;
  }
};

struct SegmentTree {
  vector<node> nodes;

  SegmentTree(int _n) {
    nodes.resize(1 << (33 - __builtin_clz(_n - 1)));
  }

  void push(int i, int nl, int nr) {
    if (nodes[i].lazy != 0) {
      int mid = (nl + nr) / 2;
      nodes[2 * i].apply(nl, mid, nodes[i].lazy);
      nodes[2 * i + 1].apply(mid + 1, nr, nodes[i].lazy);
      nodes[i].lazy = 0;
    }
  }

  void modify(int ql, int qr, int x, int i, int nl, int nr) {
    if (qr < nl || ql > nr) return;
    if (ql <= nl && nr <= qr) {
      nodes[i].apply(nl, nr, x);
      return;
    }
    push(i, nl, nr);
    int mid = (nl + nr) / 2;
    modify(ql, qr, x, 2 * i, nl, mid);
    modify(ql, qr, x, 2 * i + 1, mid + 1, nr);
    nodes[i] = nodes[2 * i].combine(nodes[2 * i + 1]);
  }

  node query(int ql, int qr, int i, int nl, int nr) {
    if (qr < nl || ql > nr) return node();
    if (ql <= nl && nr <= qr) return nodes[i];
    push(i, nl, nr);
    int mid = (nl + nr) / 2;
    node a = query(ql, qr, 2 * i, nl, mid);
    node b = query(ql, qr, 2 * i + 1, mid + 1, nr);
    return a.combine(b);
  }

  int bs(int ql, int qr, int x, int i, int nl, int nr) {
    if (nl > qr || nr < ql || nodes[i].sum < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    }
    push(i, nl, nr);
    int mid = (nl + nr) / 2;
    int a = bs(ql, qr, x, 2 * i, nl, mid);
    if (a != -1) {
      return a;
    }
    return bs(ql, qr, x - nodes[2 * i].sum, 2 * i + 1, mid + 1, nr);
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  SegmentTree st(N);
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt & 1) {
      int l, r;
      cin >> l >> r;
      r--;
      st.modify(l, r, 1, 1, 0, N - 1);
    } else {
      int idx;
      cin >> idx;
      // yedinci 1 neredeyi bile 0 indexli soruyor
      cout << st.bs(0, N - 1, idx + 1, 1, 0, N - 1) << '\n';
    }
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