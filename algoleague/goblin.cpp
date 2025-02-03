#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, dx, dy;
  cin >> N >> dx >> dy;
  vector<pair<int, int>> a, b;
  int A = N / 2, B = N - A;
  for (int i = 0; i < A; ++i) {
    int x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
  }
  for (int i = 0; i < B; ++i) {
    int x, y;
    cin >> x >> y;
    b.emplace_back(x, y);
  } 
  vector<map<pair<int, int>, int>> mp1(21), mp2(21);
  for (int i = 0; i < (1 << A); ++i) {
    int x = 0, y = 0;
    for (int j = 0; j < A; ++j) {
      if ((i >> j) & 1) {
        x += a[j].first, y += a[j].second;
      }
    }
    mp1[__builtin_popcount(i)][{x, y}]++;
  }
  for (int i = 0; i < (1 << B); ++i) {
    int x = 0, y = 0;
    for (int j = 0; j < B; ++j) {
      if ((i >> j) & 1) {
        x += b[j].first, y += b[j].second;
      }
    }
    mp2[__builtin_popcount(i)][{x, y}]++;
  }
  vector<int> ans(40);
  for (int i = 0; i <= A; ++i) {
    for (auto& [x, y] : mp1[i]) {
      for (int j = 0; j <= B; ++j) {
        ans[i + j] += y * mp2[j][{dx - x.first, dy - x.second}];
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << '\n';
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