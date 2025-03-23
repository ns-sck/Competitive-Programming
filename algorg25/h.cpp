#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  double r;
  cin >> r;
  auto dis = [&](int i, int j, int x, int y) {
    int d1 = abs(x - i);
    int d2 = abs(y - j);
    return d1 * d1 + d2 * d2;
  };
  int ans = 0;
  for (int i = 0; i < 500; ++i) {
    for (int j = 0; j < 500; ++j) {
      int c = 0;
      int x = i + r * 1000;
      int y = j + r * 1000;
      while (y >= 0) {
        int d = dis(i, j, x, y);
        if (d == r * r) {
          c++;
          x++;
          y--;
        } else if (d < r * r) {
          x++;
        } else {
          y--;
        }
      } 
      while (x >= 0) {
        int d = dis(i, j, x, y);
        if (d == r * r) {
          c++;
          x--;
          y--;
        } else if (d < r * r) {
          y--;
        } else {
          x--;
        }
      }
      while (y <= 0) {
        int d = dis(i, j, x, y);
        if (d == r * r) {
          c++;
          x--;
          y++;
        } else if (d < r * r) {
          x--;
        } else {
          y++;
        }
      } 
      while (x <= 0) {
        int d = dis(i, j, x, y);
        if (d == r * r) {
          c++;
          x++;
          y++;
        } else if (d < r * r) {
          y++;
        } else {
          x++;
        }
      } 
      ans = max(ans, c);
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}