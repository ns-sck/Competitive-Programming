#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  int ans = 0;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  for (int i = 0; i < N; ++i) {
    if (arr[i] == 0) continue;
    int j = i;
    while (j < N && arr[j]) ++j;
    i = j - 1;
    ++ans;
  }
  cout << min(ans, 2ll) << '\n';
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