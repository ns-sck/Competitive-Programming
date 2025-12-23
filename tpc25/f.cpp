#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<vector<int>> grid(N, vector<int>(M));
  vector<set<int>> points(N);
  priority_queue<array<int, 3>> pq;
  int c = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> grid[i][j];
      pq.push({grid[i][j], i, j});
      if (i + X <= N && j + Y <= M) {
        points[i].insert(j);
        c++;
      }
    }
  }
  int ans = 0;
  debug(pq.size());
  while (c > 0) {
    auto[x, i, j] = pq.top();
    debug(x, i, j);
    pq.pop();
    int lft = 0;
    if (j - Y + 1 > 0) {
      lft = j - Y + 1;
    } 
    int r = 0;
    if (i - X + 1 > 0) {
      r = i - X + 1;
    }
    int rght = j;
    for (; r <= i; ++r) {
      auto it = points[r].lower_bound(lft);
      vector<set<int>::iterator> del;
      while (it != points[r].end() && *it <= rght) {
        ans += x;
        del.push_back(it);
        ++it;
        c--;
      }
      for (auto it : del) {
        points[r].erase(it);
      }
    }
  }
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