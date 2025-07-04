#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  if (N & 1) {
    cout << (N / 2 + (N / 2) * (N / 2)) + 1 << '\n';
  } else {
    cout << (N * N / 4 + 1) << '\n';
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