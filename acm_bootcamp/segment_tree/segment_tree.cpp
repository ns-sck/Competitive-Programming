#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int INF = 1ll << 61;

#define lch 2 * i
#define rch 2 * i + 1

struct Node {
  int sum = 0;
  int mn = INF;
  int mx = -INF;
  int xorr = 0;

  Node merge(const Node& other) {
    Node ret;
    ret.sum = sum + other.sum;
    ret.mn = min(mn, other.mn);
    ret.mx = max(mx, other.mx);
    ret.xorr = xorr ^ other.xorr;
    return ret;
  }

  void apply(int val, int nl, int nr) {
    sum += val;
    xorr ^= val;
    mn += val;
    mx += val;
  }
};

class SimpleSegmentTree {
  vector<Node> nodes;
  int n_;

public:
  SimpleSegmentTree(int n) {
    n_ = 1ll << (65 - __builtin_clzll(n - 1));
    nodes.resize(n_);
  }

  void build(vector<int>& arr, int i, int nl, int nr) {
    if (nl == nr) {
      nodes[i].sum = arr[nl];
      nodes[i].mn = arr[nl];
      nodes[i].mx = arr[nl];
      nodes[i].xorr = arr[nl];
      return;
    }
    int mid = (nl + nr) / 2;
    build(arr, lch, nl, mid);
    build(arr, rch, mid + 1, nr);
    nodes[i] = nodes[lch].merge(nodes[rch]);
  }

  void modify(int val, int ql, int qr, int i, int nl, int nr) {
    if (ql > nr || qr < nl) {
      return;
    }
    if (nl == nr) {
      nodes[i].apply(val, nl, nr);
      return;
    }
    int mid = (nl + nr) / 2;
    modify(val, ql, qr, lch, nl, mid);
    modify(val, ql, qr, rch, mid + 1, nr);
    nodes[i] = nodes[lch].merge(nodes[rch]);
  }

  Node query(int ql, int qr, int i, int nl, int nr) {
    if (ql > nr || qr < nl) {
      return Node();
    }
    if (ql <= nl && nr <= qr) {
      return nodes[i];
    }
    int mid = (nl + nr) / 2;
    Node a = query(ql, qr, lch, nl, mid);
    Node b = query(ql, qr, rch, mid + 1, nr);
    return a.merge(b);
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  SimpleSegmentTree st(N);
  vector<int> arr(N);
  debug(arr);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  st.build(arr, 1, 0, N - 1);
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    Node a = st.query(l, r, 1, 0, N - 1);
    cout << a.mn << '\n';
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