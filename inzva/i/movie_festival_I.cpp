#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// https://cses.fi/problemset/task/1629

void solve() {
  int N;
  cin >> N;
  vector<pair<int, int>> arr(N);
  for (int i = 0; i < N; ++i) {
    int start, end;
    cin >> start >> end;
    arr[i] = {end, start};
  }
  // sort intervals by ending times
  sort(arr.begin(), arr.end());
  int last = 0, ans = 0;
  // we get interval1 before interval2 if it ends before
  for (auto [e, s] : arr) {
    // if start of the current interval >= last finished interval
    if (s >= last) {
      // take this interval and set last finished interval as e for next operations
      ans++;
      last = e;
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