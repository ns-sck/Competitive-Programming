#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, X, Y;
  cin >> N >> X >> Y;
  if (X > Y) swap(X, Y);
  vector<int> ans(N + 1);
  ans[X] = 1, ans[Y] = 2;
  int j = 0;
  for (int i = X + 1; i < Y; ++i) {
    ans[i] = j;
    j ^= 1;
  }
  j = 0;
  for (int i = X - 1; i; --i) {
    ans[i] = j;
    j ^= 1;
  }
  for (int i = N; i > Y; --i) {
    ans[i] = j;
    j ^= 1;
  }
  set<int> a;
  a.emplace(ans[Y - 1]);
  a.emplace(ans[X]);
  a.emplace(Y < N ? ans[Y + 1] : ans[1]);
  if (a.size() == 1) ans[Y] = *a.begin() ^ 1;
  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << " \n"[i == N];
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