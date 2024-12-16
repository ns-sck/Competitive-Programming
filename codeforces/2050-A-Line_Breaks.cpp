#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  int ans = 0;
  while (N--) {
    string s; cin >> s;
    int x = s.length();
    if (M >= x) {
      M -= x;
      ++ans;
    } else {
      for (int i = 0; i < N; ++i) {
        cin >> s;
      }
      break;
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