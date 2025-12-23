#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, X, Y;
  cin >> N >> X >> Y;
  string S;
  cin >> S;
  vector<int> p(N);
  int x = X, y = Y, s = 0, t = 0, ev = 0;
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
    s += p[i];
    t += p[i] - (p[i] + 2) / 2;
    ev = ~p[i] & 1;
    if (S[i] == '0') {
      x -= (p[i] + 2) / 2;
    } else {
      y -= (p[i] + 2) / 2;
    }
  }
  bool bad = (X + Y < s);
  bad = bad || (min(x, y) < 0);
  int z = count(S.begin(), S.end(), '0');
  if (z == N && Y > X - N) bad = 1;
  if (z == 0 && X > Y - N) bad = 1;
  if (bad) cout << "NO\n";
  else cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}