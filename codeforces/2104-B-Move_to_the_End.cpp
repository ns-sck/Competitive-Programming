#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  vector<int> seen(N);
  for (int i = 0, mx = 0; i < N; ++i) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
    seen[i] = mx;
  }
  for (int i = N - 1, sum = 0; ~i; --i) {
    cout << sum + seen[i] << " \n"[!i];
    sum += arr[i];
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