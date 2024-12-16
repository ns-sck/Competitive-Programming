#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> pref(N + 1, vector<int>(N + 1)), stab(N + 1, vector<int>(N + 1)), norm(N + 1, vector<int>(N + 1));
  vector<vector<int>> g(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> g[i][j];
      pref[i][j] += pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + g[i][j] * ((i - 1) * N + j);
      stab[i][j] += stab[i][j - 1] + stab[i - 1][j] - stab[i - 1][j - 1] + g[i][j] * i;
      norm[i][j] += norm[i][j - 1] + norm[i - 1][j] - norm[i - 1][j - 1] + g[i][j];
    }
  }
  int a, b, c, d;
  auto rng = [&](vector<vector<int>>& v) {
    return v[c][d] - v[c][b - 1] - v[a - 1][d] + v[a - 1][b - 1];
  };
  while (Q--) {
    cin >> a >> b >> c >> d;
    int ans = rng(pref);
    int idx = (a - 1) * N + b;
    ans -= rng(norm) * (idx - 1);
    int k = (N - (d - b + 1) );
    int x = rng(stab), y = rng(norm);
    ans -= (x - a * y) * k;
    cout << ans << ' ';
  }
  cout << '\n';
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