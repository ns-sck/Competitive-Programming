#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  auto hamm = [&](string a, string b) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 'A' || a[i] == 'T') {
        ans += b[i] == 'C' || b[i] == 'G';
      }  else {
        ans += b[i] == 'A' || b[i] == 'T';
      }
    }
    return ans;
  };
  int ans = 0;
  auto f = [&](auto&& self, int i, string s) -> void {
    if (i == n) {
      cout << s << '\n';
      ans += hamm(s, a) == hamm(s, b);
      return;
    }
    string ss = s;
    ss += 'A';
    self(self, i + 1, ss);
    ss.back() = 'T';
    self(self, i + 1, ss);
    ss.back() = 'C';
    self(self, i + 1, ss);
    ss.back() = 'G';
    self(self, i + 1, ss);
  };
  f(f, 0, "");
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}