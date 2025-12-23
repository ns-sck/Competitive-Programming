#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> vis(2 * n);
  int aa = 0, bb = 0, cc = 0;
  for (auto& x : s) {
    if (x =='A') aa++;
    else if (x == 'B') bb++;
    else cc++;
  }

  int th = ((bb + cc) - aa) / 2;

  queue<int> b;
  vector<pair<int, int>> vp;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == 'B') b.push(i + 1);
    else if (s[i] == 'C' && b.size() && th > 0) {
      vp.push_back({b.front(), i + 1});
      vis[i] = vis[b.front() - 1] = 1;
      th--;
      b.pop();
    }
  }
  queue<int> a;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == 'A') a.push(i + 1);
    else if (a.size() && !vis[i]) {
      vp.push_back({a.front(), i + 1});
      a.pop();
    }
  }

  if (vp.size() != n) cout << "NO" << '\n';
  else {
    cout << "YES\n";
    for (auto [l, r] : vp) cout << l << ' ' << r << '\n';
  }


  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}