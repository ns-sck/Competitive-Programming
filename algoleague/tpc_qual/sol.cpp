#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 5e5;
constexpr int mxN = 2e5;

void solve() {
  int N;
  cin >> N;
  assert(2 <= N <= mxN);
  vector<int> arr(N);
  vector<int> pref(MAX + 1);
  vector<int> cnt(MAX + 1);
  vector<vector<int>> cml(MAX + 1);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    assert(2 <= arr[i] <= MAX);
    cnt[arr[i]]++;
    pref[arr[i]]++;
    cml[arr[i]].push_back(arr[i]);
  }
  for (int i = 1; i <= MAX; ++i) {
    pref[i] += pref[i - 1];
  }
  sort(arr.begin(), arr.end());
  int ans = -N, ans2 = -N;
  for (int& x : arr) {
    for (int i = 1; i <= MAX / x; ++i) {
      ans += i * (pref[min(MAX, (i + 1) * x - 1)] - pref[i * x - 1]);
    }
  }
  int count = 0;
  for (int i = 0; i <= MAX; ++i) {
    count += cml[i].size();
    ans2 += cnt[i] * count;
    for (int& x : cml[i]) {
      if (i + x <= MAX) {
        cml[i + x].push_back(x);
      }
      cml[i] = {};
    }
  }
  assert(ans == ans2);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
