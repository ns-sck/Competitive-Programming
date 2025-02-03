#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  int x = 0;
  while (N--) {
    int a;
    cin >> a;
    x ^= a;
  }
  if (x) cout << "first" << '\n';
  else cout << "second" << '\n';
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