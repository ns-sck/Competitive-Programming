#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<int> ans(N);
  map<int, int> last;
  for (int i = 0; i < N; ++i) {
    int x = arr[i];
    if (!last.count(x) || (i - last[x]) % 2 == 1) {
      ++ans[x - 1];
    } 
    last[x] = i;
  }
  for (int& x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
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