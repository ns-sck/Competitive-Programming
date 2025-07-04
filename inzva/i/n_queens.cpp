#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// problem: how many times you can place N queens onto N * N board
// not a dp problem but gives idea about bitmasks
int rec(int i, int n, int column, int diagonal, int anti_diagonal) {
  if (i == n) {
    return column == (1 << n) - 1;
  }
  int ans = 0;
  for (int j = 0; j < n; ++j) {
    int diag = n + i - j - 1;
    int antidiag = i + j;
    if (column & (1 << j) || diagonal & (1 << diag) || anti_diagonal & (1 << antidiag)) continue;
    ans += rec(i + 1, n, column | (1 << j), diagonal | (1 << diag), anti_diagonal | (1 << antidiag));
  }
  return ans;
}

void solve() {
  int N;
  cin >> N;
  cout << rec(0, N, 0, 0, 0) << '\n';
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