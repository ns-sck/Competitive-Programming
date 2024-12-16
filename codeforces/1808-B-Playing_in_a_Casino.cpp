#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> arr(M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int x; cin >> x;
      arr[j].emplace_back(x);
    }
  }
  int ans = 0;
  for (auto& v : arr) sort(v.begin(), v.end());
  for (auto& v : arr) {
    int s = v[0];
    for (int i = 1; i < N; ++i) {
      ans += i * v[i] - s;
      s += v[i];
    }
  }
  cout << ans << '\n';
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