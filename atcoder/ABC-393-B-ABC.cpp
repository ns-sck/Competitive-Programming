#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 2; i < S.size(); ++i) {
    for (int j = i - 1; ~j; --j) {
      int k = j - (i - j);
      if (S[k] == 'A' && S[j] == 'B' && S[i] == 'C') ++ans;
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