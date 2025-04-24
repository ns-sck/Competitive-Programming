#include <bits/stdc++.h>
using namespace std;

#define int int64_t

struct BIT2D {
  vector<vector<int>> bit;
  int n, m; // give + 1

  BIT2D(int n, int m) : n(n), m(m) {
    bit.assign(n, vector<int>(m, 0));
  }

  int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
      for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
        ret += bit[i][j];
      }
    }
    return ret;
  }

  void add(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1)) {
      for (int j = y; j < m; j = j | (j + 1)) {
        bit[i][j] += delta;
      }
    }
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> grid(N + 1, vector<int>(N + 1));
  BIT2D bit(N + 1, N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c == '*';
      bit.add(i, j, grid[i][j]);
    }
  }
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt & 1) {
      int i, j;
      cin >> i >> j;
      int a = grid[i][j];
      grid[i][j] ^= 1;
      bit.add(i, j, grid[i][j] - a);
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << bit.sum(x2, y2) + bit.sum(x1 - 1, y1 - 1) - bit.sum(x1 - 1, y2) - bit.sum(x2, y1 - 1) << '\n';
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