#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string S;
  cin >> S;
  // 2 -> 4
  // 3 -> 9
  int s = 0;
  int N = S.length(), a = 0, b = 0;
  for (int i = 0; i < N; ++i) {
    s += S[i] - '0';
    if (S[i] == '2') ++a;
    else if (S[i] == '3') ++b;
  }
  int md = s % 9;
  for (int i = 0; i <= min(a, 30ll); ++i) {
    for (int j = 0; j <= min(b, 20ll); ++j) {
      int x = 2 * i + 6 * j;
      if (((md + x) % 9) == 0) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
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