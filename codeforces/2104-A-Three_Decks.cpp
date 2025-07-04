#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int A, B, C;
  cin >> A >> B >> C;
  C -= B - A;
  if (C >= B && (C - B) % 3 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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