#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int l, r, x;
  cin >> l >> r >> x;
  int start = (l + x - 1) / x * x;
  int end = r / x * x;
  int best = -1;
  int a = -1, b = -1;
  for (int i = start; i <= end && end - i > best; i += x) {
    for (int j = end; j >= start && j - i > best; j -= x) {
      if (__gcd(i, j) == x && j - i > best) {
        best = j - i;
        a = i;
        b = j;
      } 
    }
  }
  cout << a << ' ' << b << '\n';
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