#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 1e7 + 1;
vector<int> spf(MAX);
vector<int> prs;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      prs.push_back(i);
    }
    for (int j = 0; i * prs[j] < MAX; ++j) {
      spf[i * prs[j]] = prs[j];
      if (prs[j] == spf[i]) {
        break;
      }
    }
  }
}

void solve() {
  sieve();
  int ans = 0;
  for (int i = 0; i < prs.size() - 1; ++i) {
    ans = max(ans, prs[i + 1] - prs[i]);
    debug(ans);
  }
  cout << ans << "\n";
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