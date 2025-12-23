#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

vector<int> tree(1 << 19);

void update(int val, int idx, int i, int nl, int nr) {
  if (idx < nl || idx > nr) {
    return;
  }
  if (nl == nr) {
    tree[i] = val;
    return;
  }
  int mid = (nl + nr) / 2;
  update(val, idx, 2 * i, nl, mid);
  update(val, idx, 2 * i + 1, mid + 1, nr);
  tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  tree[i] = tree[2 * i] + tree[2 * i + 1];
  tree[i]
}

int query(int ql, int qr, int i, int nl, int nr) {
  if (qr < nl || ql > nr) {
    return 0;
  }
  if (ql <= nl && qr >= nr) {
    return tree[i];
  }
  int mid = (nl + nr) / 2;
  int left_part = query(ql, qr, 2 * i, nl, mid);
  int right_part = query(ql, qr, 2 * i + 1, mid + 1, nr);
  return left_part + right_part;
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    update(arr[i], i, 1, 0, N - 1);
  }
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt == 2) {
      int a, b;
      cin >> a >> b;
      // 1 indexed input, 0 indexed array
      a--, b--;
      cout << query(a, b, 1, 0, N - 1) << '\n';
    } else {
      int idx, val;
      cin >> idx >> val;
      // 1 indexed input, 0 indexed array
      idx--;
      update(val, idx, 1, 0, N - 1);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}