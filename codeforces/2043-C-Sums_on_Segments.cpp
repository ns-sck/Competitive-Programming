#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  auto get_mx = [&](int l, int r) {
    int sum = 0, ans = 0;
    for (int i = l; i <= r; ++i) {
      sum += arr[i];
      if (sum < 0) {
        sum = 0;
      }
      ans = max(sum, ans);
    }
    return ans;
  };
  auto get_mn = [&](int l, int r) {
    int sum = 0, ans = 0;
    for (int i = l; i <= r; ++i) {
      sum += arr[i];
      if (sum > 0) {
        sum = 0;
      }
      ans = min(ans, sum);
    }
    return ans;
  };
  int idx = 0;
  for (int i = 0; i < N; ++i) {
    if (abs(arr[i]) > 1) idx = i;
  }
  int lmn = get_mn(0, idx - 1);
  int lmx = get_mx(0, idx - 1);
  int rmn = get_mn(idx + 1, N - 1);
  int rmx = get_mx(idx + 1, N - 1);
  int rrmx = 0, rrmn = 0, llmx = 0, llmn = 0;
  int sum = 0;
  for (int i = idx + 1; i < N; ++i) {
    sum += arr[i];
    rrmx = max(rrmx, sum);
    rrmn = min(rrmn, sum);
  }
  sum = 0;
  for (int i = idx - 1; ~i; --i) {
    sum += arr[i];
    llmx = max(llmx, sum);
    llmn = min(llmn, sum);
  }
  set<int> ans;
  for (int i = lmn; i <= lmx; ++i) {
    ans.emplace(i);
  }
  for (int i = rmn; i <= rmx; ++i) {
    ans.emplace(i);
  }
  for (int i = arr[idx] + llmn + rrmn; i <= arr[idx]; ++i) {
    ans.emplace(i);
  }
  for (int i = arr[idx]; i <= llmx + rrmx + arr[idx]; ++i) {
    ans.emplace(i);
  }
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
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