#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;
  int x = a[N - 1];
  for (int i = 0; i < N - 1; ++i) {
    if (a[i] > x) swap(a[i], b[i]);
  }
  x = b[N - 1];
  for (int i = 0; i < N - 1; ++i) {
    if (b[i] > x) swap(a[i], b[i]);
  }
  int mx1 = *max_element(a.begin(), a.end());
  int mx2 = *max_element(b.begin(), b.end());
  if (mx1 == a[N - 1] && mx2 == b[N - 1]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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