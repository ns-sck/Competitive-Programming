#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// https://cses.fi/problemset/task/1164

void solve() {
  int N;
  cin >> N;
  vector<array<int, 3>> arr(N);
  for (int i = 0; i < N; ++i) {
    int start, end;
    cin >> start >> end;
    arr[i] = {start, end, i};
  }
  // easy solution, sort by starting times
  // if there is some room which is empty, use it
  // else allocate one more room and use it
  sort(arr.begin(), arr.end());
  int cnt = 1;
  // pq to track the state of the rooms
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, 1});
  vector<int> ans(N);
  for (int i = 0; i < N; ++i) {
    auto [s, e, idx] = arr[i];
    auto [ends, room] = pq.top();
    // we can use this room, no need to allocate a new room
    if (ends < s) {
      pq.pop();
      ans[idx] = room;
      pq.push({e, room});
    // even the first ending room is not empty, so allocate a new room
    } else {
      cnt++;
      ans[idx] = cnt;
      pq.push({e, cnt});
    }
  }
  cout << cnt << '\n';
  for (int& x : ans) {
    cout << x << ' ';
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