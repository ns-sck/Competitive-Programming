#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int M;
  cin >> M;
  map<int, int> mp;
  vector<vector<int>> arr(M);
  for (int i = 0; i < M; ++i) {
    int n; cin >> n;
    for (int j = 0; j < n; ++j) {
      int x; cin >> x;
      arr[i].emplace_back(x);
      mp[x] = i;
    }
  }
  vector<int> ans;
  for (int i = 0; i < M; ++i) {
    for (auto x : arr[i]) {
      if (mp[x] == i) {
        ans.emplace_back(x);
        break;
      }
    }
  }
  if (ans.size() == M) {
    for (auto x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
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