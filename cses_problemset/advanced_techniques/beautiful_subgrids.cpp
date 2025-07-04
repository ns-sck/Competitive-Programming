#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  int ans = 0;
  vector<bitset<3000>> arr(N);
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < N; ++j) {
      if (s[j] == '1') {
        arr[i].flip(j);
      }
    }
    for (int j = 0; j < i; ++j) {
      int c = (arr[i] & arr[j]).count();
      ans += c * (c - 1) / 2;
    }
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