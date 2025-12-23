#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int INF = 1ll << 61;

int n;

struct node {
  int x, y, z, t;
} st[1 << 19];

void upd(int l1, int x, int i = 1, int l2 = 0, int r2 = n-1) {
  if (l2 == r2) {
    st[i].x = 0;
    st[i].y = 0;
    st[i].z = 0;
    st[i].t = x;
    return;
  }
  int m2 = (l2+r2)/2;
  if (l1 <= m2)
    upd(l1, x, 2*i, l2, m2);
  else
    upd(l1, x, 2*i+1, m2+1, r2);
  st[i].x = max(st[2*i].x + st[2*i+1].x, st[2*i].z + st[2*i+1].t);
  st[i].y = max(st[2*i].y + st[2*i+1].y, st[2*i].t + st[2*i+1].z);
  st[i].z = max(st[2*i].x + st[2*i+1].z, st[2*i].z + st[2*i+1].y);
  st[i].t = max(st[2*i].t + st[2*i+1].x, st[2*i].y + st[2*i+1].t);
}

node qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n-1) {
  if (l1 <= l2 && r2 <= r1) {
    return st[i];
  }
  int m2 = (l2+r2)/2;
  node q1 = l1 <= m2 ? qry(l1, r1, 2*i, l2, m2) : node();
  node q2 = m2 < r1 ? qry(l1, r1, 2*i+1, m2+1, r2) : node();
  node q;
  q.x = max(q1.x + q2.x, q1.z + q2.t);
  q.y = max(q1.y + q2.y, q1.t + q2.z);
  q.z = max(q1.x + q2.z, q1.z + q2.y);
  q.t = max(q1.t + q2.x, q1.y + q2.t);
  return q;
}

void solve() {
  int N, Q;
  cin >> n >> Q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    upd(i, max(a[i], 0ll));
  }
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int i, x;
      cin >> i >> x;
      upd(i - 1, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << qry(l - 1, r - 1).t << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}