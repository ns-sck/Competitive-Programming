#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  if (b > a + 100) {
    while (a <= b) {
      string s = to_string(a);
      bool zero = 0, nine = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') zero = 1;
        if (s[i] == '9') nine = 1;
      }
      if (zero && nine) {
        cout << s << '\n';
        return;
      }
      ++a;
    }
  } else {
    int diff = 0, mx = a;
    while (a <= b) {
      string s = to_string(a);
      sort(s.begin(), s.end());
      int z = s[s.size() - 1] - s[0];
      if (z > diff) {
        diff = z;
        mx = a;
      }
      ++a;
    }
    cout << mx << '\n';
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