#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string S;
  cin >> S;
  int N = S.size();
  if (N == 1) {
    cout << "1 1 1 1\n";
    return;
  }
  string A = S.substr(1, N - 1);
  int l = 0, r = 0, mx = 0;
  for (int i = 1; i < N; ++i) {
    int best = 0;
    for (int j = 0; j < i; ++j) {
      int a = 0, len = N - i;
      int ii = i, jj = j;
      while (S[ii] != S[jj]) {
        ++a, ++ii, ++jj;
      }
      if (a > best) {
        l = j + 1, r = j + N - i;
        best = a;
      }
    }
    if (l) {
      cout << 1 << ' ' << N << ' ' << l << ' ' << r << '\n';
      return;
    }
  }
  cout << 1 << ' ' << N << ' ' << N << ' ' << N << '\n'; 
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