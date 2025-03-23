#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<int> used(N, -1);
  int i = N - 1;
  int c = 0;
  string ans = "No";
  bool ok = 0;
  while (1) {
    if (arr[i] > N) break;
    used[i] = c++;
    i = i - arr[i];
    if (i < 0) i += N;
    if (~used[i]) {
      ok = 1;
      break;
    }
  }
  for (int i = 0; i < N && ok; ++i) {
    if (used[i] == -1) continue;
    if ((K - used[i]) % c == 0) ans = "Yes";
  }
  if (c >= K) ans = "Yes";
  cout << ans << '\n';
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