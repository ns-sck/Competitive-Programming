#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  for (int i = 0; i < N - 1; ++i) {
    int x = min(arr[i], arr[i + 1]);
    arr[i] -= x;
    arr[i + 1] -=x;
  }
  for (int i = 0; i < N - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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