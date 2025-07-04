#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if (!arr.size() || x ^ arr.back()) arr.push_back(x); 
  }
  for (int i = 0; i < arr.size(); ++i) {
    ans += max(i ? arr[i - 1] : -1, i < arr.size() - 1 ? arr[i + 1] : -1) < arr[i];
  }
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