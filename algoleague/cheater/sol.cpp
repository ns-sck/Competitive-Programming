#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  assert(1 <= N <= 1e6);
  assert(1 <= M <= 1e6);
  assert(0 <= K <= 5);
  vector<string> grid(N);
  for (string& s : grid) {
    cin >> s;
    for (char& c : s) {
      assert(c == '.' || c == '#');
    }
  }
  int dr, dc;
  cin >> dr >> dc;
  // assert(0 <= dr < N);
  // assert(0 <= dc < M); // ?? ? ?
  array<int, 2> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector<vector<vector<int>>> dis(N, vector<vector<int>>(M, vector<int>(K + 1, 1 << 30)));
  queue<array<int, 4>> que;
  que.push({dr, dc, 0, 0});
  while (que.size()) {
    auto [r, c, d, x] = que.front();
    que.pop();
    if (dis[r][c][x] < d) continue;
    for (auto [a, b] : dir) {
      int ii = r + a, jj = c + b;
      if (~ii && ii < N && ~jj && jj < M) {
        if (grid[ii][jj] == '#' && x < K && dis[ii][jj][x + 1] > d + 1) {
          dis[ii][jj][x + 1] = d + 1;
          que.push({ii, jj, d + 1, x + 1});
        } 
        if (grid[ii][jj] == '.' && dis[ii][jj][x] > d + 1) {
          dis[ii][jj][x] = d + 1;
          que.push({ii, jj, d + 1, x});
        } 
      }
    }
  }
  int s;
  cin >> s;
  // assert(s > 0);
  int ans = 1 << 30;
  for (int i = 0; i < s; ++i) {
    int r, c;
    cin >> r >> c;
    // assert(0 <= r < N);
    // assert(0 <= c < M);
    for (int j = 0; j <= K; ++j) {
      ans = min(ans, dis[r][c][j]);
    }
  }
  if (ans == 1 << 30) ans = -1;
  cout << ans << '\n';
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