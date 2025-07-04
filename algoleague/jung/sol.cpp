#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;

void solve() {
  int N, K;
  cin >> N >> K;
  assert(1 <= N <= 44444);
  assert(1 <= K <= 1e9);
  vector<int> arr(N);
  for (int& x : arr) {
    cin >> x;
    assert(1 <= x <= 1e9);
  }
  sort(arr.begin(), arr.end());
  vector<int> divs;
  for (int i = 1; i <= sqrt(K); ++i) {
    if (K % i == 0) {
      divs.push_back(i);
      if (i * i != K) {
        divs.push_back(K / i);
      }
    }
  }
  sort(divs.begin(), divs.end());
  int n = divs.size();
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[divs[i]] = i;
  }
  vector<int> ans(n);
  ans[0] = 1;
  for (int& x : arr) {
    for (int i = n; ~i; --i) {
      if (divs[i] % x == 0) {
        ans[i] = (ans[i] + ans[mp[divs[i] / x]]) % MOD;
      }
    }
  }
  if (K == 1) ans.back()--;
  cout << ans.back() << '\n';
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