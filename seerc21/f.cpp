#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, X, R, P, K;
  string S;
  cin >> N >> X >> R >> P >> K >> S;
  int ans = X * N;
  set<int> av, one;
  for (int i = 1; i <= N; ++i) {
    av.insert(i);
    if (S[i - 1] == '1') {
      one.insert(i);
      ans -= (N - i + 1) * R;
    }
  }
  for (int i = 0; i < K; ++i) {
    int a = *(av.begin());
    auto it = one.begin();
    if (it == one.end()) {
      av.erase(a);
      ans += (N - a + 1) * P;
    } else {
      int use1 = (N - a + 1) * P;
      int use2 = (N - (*it) + 1) * (P + R);
      ans += max(use1, use2);
      if (*it == a) {
        av.erase(a);
        one.erase(it);
      } else if (use1 >= use2) {
        av.erase(a);
      } else {
        av.erase(*it);
        one.erase(it);
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}