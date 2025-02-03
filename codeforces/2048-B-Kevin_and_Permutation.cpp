#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> ans(N);
  int x = 1;
  for (int i = K - 1; i < N; i += K) {
    ans[i] = x++;
  }
  for (int j = 0; j < N; ++j) {
    if (ans[j]) continue;
    ans[j] = x++;
  }
  for (auto& x : ans) cout << x << ' ';
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