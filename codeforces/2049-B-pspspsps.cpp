#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  string S;
  cin >> N >> S;
  int p = -1, s = N + 1;
  bool b = 0, x = 0, y = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '.') continue;
    if (S[i] == 's') {
      if (i) x = 1;
      for (int j = 0; j < i; ++j) {
        if (S[j] == 'p') {
          cout << "NO\n";
          return;
        }
      }
    } else {
      if (i < N - 1) y = 1;
    }
  }
  if (x && y) {
    cout << "NO\n";
  }
  else cout << "YES\n";
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