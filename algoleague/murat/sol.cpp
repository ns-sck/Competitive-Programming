#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int R, C, S;
  cin >> R >> C >> S;
  vector<vector<int>> grid(R, vector<int>(C));
  for (auto& r : grid) {
    for (auto& c : r) {
      cin >> c;
    }
  }
  int msk = (1 << 30) - 1;
  array<int, 2> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (int s = 0; s < S; ++s) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        int sum = 0, cnt = 0;
        for (auto& [r, c] : d) {
          int ii = i + r, jj = j + c;
          if (~ii && ii < R && ~jj && jj < C) {
            ++cnt;
            sum += grid[ii][jj] & msk;
          }
        }
        debug(sum, cnt);
        if (cnt) {
          grid[i][j] |= (sum / cnt) << 30;
        }
      }
    }
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        grid[i][j] >>= 30;
      }
    }
  }
  for (auto& r : grid) {
    for (auto& c : r) {
      cout << c << ' ';
    }
    cout << '\n';
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