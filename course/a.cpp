#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<pair<int, int>> arr(N);
  for (int i = 0; i < N; ++i) {
    int start, end;
    cin >> start >> end;
    arr[i] = {end, start};
  }
  sort(arr.begin(), arr.end());
  int last = 0;
  int ans = 0;
  for (auto [end, start] : arr) {
    if (start >= last) {
      ++ans;
      last = end;
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}