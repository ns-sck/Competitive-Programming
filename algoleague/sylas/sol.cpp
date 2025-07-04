#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  // assert(1 <= N)
  vector<int> arr(N);
  vector<int> ans(N);
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    ans[i] = arr[i];
    assert(1 <= arr[i] <= 1e9);
    pq.emplace(-arr[i], i);
  }
  while (pq.size()) {
    auto [c, i] = pq.top();
    c = -c;
    pq.pop();
    if (ans[i] < c) continue;
    ans[i] = c;
    if (i) {
      int x = max(abs(arr[i] - arr[i - 1]), c);
      if (x < ans[i - 1]) {
        pq.emplace(-x, i - 1);
      }
    }
    if (i < N - 1) {
      int x = max(abs(arr[i] - arr[i + 1]), c);
      if (x < ans[i + 1]) {
        pq.emplace(-x, i + 1);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << ans[i] << " \n"[i == N - 1];
  }
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