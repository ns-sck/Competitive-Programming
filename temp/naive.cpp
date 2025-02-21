#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  int Q;
  cin >> Q;
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int p, x;
      cin >> p >> x;
      arr[p - 1] = x;
    } else {
      int x;
      cin >> x;
      for (int i = 0; i < N; ++i) {
        arr[i] = max(arr[i], x);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << arr[i] << " \n"[i == N - 1];
  }
}

// 8
// 1 5 2 3 4 5 7 2
// 10
// 1 3 2
// 2 6
// 1 7 1
// 2 3
// 1 8 2
// 2 0
// 1 8 4
// 2 9
// 1 7 11
// 2 3
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