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
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  stack<int> mx, mn;
  vector<int> lmx(N, -1), lmn(N, -1);
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    while (mx.size() && arr[mx.top()] < arr[i]) {
      mx.pop();
    }
    if (mx.size()) {
      lmx[i] = mx.top();
    }
    mx.push(i);
    while (mn.size() && arr[mn.top()] > arr[i]) {
      mn.pop();
    }
    if (mn.size()) {
      lmn[i] = mn.top();
    }
    mn.push(i);
  }
  mx = stack<int>{}, mn = stack<int>{};
  for (int i = N - 1; ~i; --i) {
    while (mx.size() && arr[mx.top()] <= arr[i]) {
      mx.pop();
    }
    int r = N;
    if (mx.size()) {
      r = mx.top();
    }
    ans += arr[i] * ((r - i) * (i - lmx[i]) - 1);
    mx.push(i);
    while (mn.size() && arr[mn.top()] >= arr[i]) {
      mn.pop(); 
    }
    r = N;
    if (mn.size()) {
      r = mn.top();
    }
    ans -= arr[i] * ((r - i) * (i - lmn[i]) - 1);
    mn.push(i);
  }
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