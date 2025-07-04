#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string S;
  cin >> S;
  int n = S.size();
  vector<int> a(26);
  for (char& c : S) a[c - 'A']++;
  int x = -1;
  for (int i = 0; i < n; ++i) {
    int y = -1;
    for (int j = 0; j < 26; ++j) {
      if (!a[j]) continue;
      if (a[j] > (n - i + 1) / 2) {
        cout << -1 << '\n';
        return;
      } 
      if ((n - i) & 1 && (a[j] == (n - i + 1) / 2)) {
        y = j;
        break;
      } 
      if (y == -1 && x ^ j) {
        y = j;
      }
    }
    a[y]--;
    x = y;
    char c = 'A' + y;
    cout << c;
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