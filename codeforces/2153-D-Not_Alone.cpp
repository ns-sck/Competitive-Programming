#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  deque<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  auto f = [&](deque<int>& a) {
    vector<int> dp(N, 1ll << 61);
    dp[0] = 1ll << 61;
    for (int i = 1; i < N; ++i) {
      vector<int> nums{a[i]};
      for (int j = 1; j <= 2; ++j) {
        if (i - j < 0) break;
        nums.push_back(a[i - j]);
        sort(nums.begin(), nums.end());
        int t = 0;
        for (int& k : nums) {
          t += abs(nums[(j + 1) / 2] - k);
        }
        if (i - j - 1 >= 0) {
          t += dp[i - j - 1];
        }
        dp[i] = min(t, dp[i]);
      }
    }
    return dp[N - 1];
  };
  int ans = 1ll << 61;
  auto arr2 = arr;
  for (int i = 0; i < 2; ++i) {
    ans = min(ans, f(arr2));
    arr2.push_front(arr2.back());
    arr2.pop_back();
    ans = min(ans, f(arr));
    arr.push_back(arr.front());
    arr.pop_front();
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}