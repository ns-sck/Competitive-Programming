#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42

// _ _ _ _ _ _
// 2 2 3 3
// 4 3 3
// 2 2 9

void solve() {
  int N, K;
  cin >> N >> K;
  set<vector<int>> combs;
  auto gen = [&](auto&& self, int n, vector<int> divs) -> void {
    if (n == 1) {
      sort(divs.begin(), divs.end());
      combs.insert(divs);
      return;
    }
    for (int i = 2; i <= 9; ++i) {
      if (n % i == 0) {
        divs.push_back(i);
        self(self, n / i, divs);
        divs.pop_back();
      } 
    }
  };
  gen(gen, N, {});
  for (auto& divs : combs) {
    debug(divs);
  }
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