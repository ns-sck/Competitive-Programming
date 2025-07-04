#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// 10 5 4 7 2 8 5 3 6 10 2
void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<int> dp(N, 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      // arr[j] holds the maximum increasing subsequence
      // with using the j'th element as last element of the subsequence
      if (arr[i] > arr[j]) {
        // so if arr[i] > arr[j], we can use i'th element as last element
        // and have 1 more element in LIS
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  // returns the max element in the array / vector etc.
  cout << *max_element(dp.begin(), dp.end());
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