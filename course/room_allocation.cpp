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
    arr[i] = {start, end};
  }
  sort(arr.begin(), arr.end());
  priority_queue<int, vector<int>, greater<>> pq;
  pq.push(0);
  int ans = 1;
  for (auto [start, end] : arr) {
    int frst = pq.top();
    if (start > frst) {
      pq.pop();
      pq.push(end);
    } else {
      ans++;
      pq.push(end);
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