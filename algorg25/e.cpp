#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  map<pair<double, double>, int> mp;
  double r;
  cin >> r;
  int aa = -2 * r - 2;
  double i = 0;
  double j = 0;
  for (; i <= 2 * r; i += 1.0) {
    j = aa;
    for (; j <= 2 * r; j += 1.0) {
      if (i == 0 && j == 0) continue;
      if (i * i + j * j > 2 * r * r) continue;
      if (i == 0) {
        double y = j / 2;
        double x = r * r - y * y;
        mp[{sqrt(x), y}]++;
        mp[{-sqrt(x), y}]++;
      } else if (j == 0) {
        double x = i / 2;
        double y = r * r - x * x;
        mp[{x * 1000, sqrt(y) * 1000}]++;
        mp[{x * 1000, -sqrt(y) * 1000}]++;
      } else {
        double p = i / 2;
        double q = j / 2;
        double disq = p * p + q * q;
        double dsq = r * r - disq;
        // m^2 (k^2 + 1) = d^2
        // m = i / j
        double msq = i * i / j * j;
        double ksq = dsq / msq - 1;
        double m = sqrt(abs(msq));
        double k = sqrt(abs(ksq));
        mp[{(p - k) * 1000, (q + m * k) * 1000}]++;
        // mp[{p - k, q - m * k}]++;
        mp[{(p + k) * 1000, (q - m * k) * 1000}]++;
        // mp[{p + k, q + m * k}]++;
      }
    }
  } 
  map<pair<int, int>, int> mp2;
  int ans = 0;
  for (auto [x, y] : mp) {
    auto [i, j] = x;
    ans = max(ans, y);
    mp2[{i, j}]++;
  }
  for (auto [x, y] : mp2) {
    ans = max(ans, y);
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