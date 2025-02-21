#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string A, B;
  cin >> A >> B;
  if (A == "sick" && A == B) {
    cout << 1 << '\n';
  } else if (A == "sick") {
    cout << 2 << '\n';
  } else if (B == "sick") {
    cout << 3 << '\n';
  } else {
    cout << 4 << '\n';
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