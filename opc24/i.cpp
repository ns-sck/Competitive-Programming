#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> a;
  for (int i = 0; i < N; ++i) {
    int w, h;
    cin >> w >> h;
    a.emplace_back(w, h);
  }
  sort(a.rbegin(), a.rend());
  int ans = 0;
  if (M > a[0].first) {
    int diff = M - a[0].first;
    ans += diff * (diff + 1) / 2;
  }
  int hmin = a[0].second;
  int curw = a[0].first;
  int i = 0;
  while (curw) {
    while (i < N && a[i].first >= curw) {
      hmin = min(hmin, a[i].second);
      ++i;
    }
    int can = hmin - 1;
    if (can >= curw) {
      ans += can - curw + 1;
    }
    --curw;
  }
  cout << ans << '\n';
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