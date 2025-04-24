#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int N, M;
    cin >> N >> M;
    vector<int> ans = {N};
    int bit = 63 - __builtin_clzll(N);
    int j = 0;
    while (N ^ M) {
      int x = 1ll << j;
      if ((N & x) == (M & x)) {
        j++;
        continue;
      }
      if (N & x) {
        N ^= x;
        ans.push_back(N);
      } else {
        int a = 0, b = 0;
        for (int i = j + 1; i <= bit; ++i) {
          int y = 1ll << i;
          if (N == y) break;
          if (N & y) {
            b = i;
            if ((M & y) == 0) {
              a = i;
            }
          }
        }
        if (a) {
          N ^= (1ll << a) | x;
          ans.push_back(N);
        } else if (b) {
          N ^= (1ll << b) | x;
          ans.push_back(N);
        } else {
          ans.push_back(-1);
          cout << -1 << '\n';
          break;
        }
      }
      j++;
    }
    if (~ans.back()) {
      cout << ans.size() - 1 << '\n';
      for (auto x : ans) {
        cout << x << " \n"[x == ans.back()];
      }
    }
  }
  // 101
  // 011
  return 0;
}
