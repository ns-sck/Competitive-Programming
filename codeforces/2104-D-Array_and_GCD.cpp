#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MAX = 8e6;

vector<int> spf(MAX);
vector<int> prs;
vector<int> pref;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      prs.push_back(i);
    }
    for (int j = 0; i * prs[j] < MAX; ++j) {
      spf[i * prs[j]] = prs[j];
      if (prs[j] == spf[i]) {
        break;
      }
    }
  }
  pref = vector<int>(prs.size() + 1);
  for (int i = 1; i <= prs.size(); ++i) {
    pref[i] = pref[i - 1] + prs[i - 1];
  }
}

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  sort(arr.rbegin(), arr.rend());
  int lo = 0, hi = N - 1, ans = hi;
  while (lo <= hi) {
    int mi = (lo + hi) >> 1;
    int left = N - mi;
    int need = pref[left];
    int sum = 0;
    for (int i = 0; i < left; ++i) {
      sum += arr[i];
    }
    if (sum < need) {
      lo = mi + 1;
    } else {
      ans = mi;
      hi = mi - 1;
    }
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  sieve();
  while (t--) {
    solve();
  }
  return 0;
}