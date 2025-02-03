#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int mp[1000001];

void solve() {
  int N;
  cin >> N;
  int ans = 1;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    ++mp[x];
  }
  for (int i = 1e6; i; --i) {
    int c = 0;
    for (int j = i; j <= 1e6; j += i) {
      c += mp[j];
    } 
    if (c > 1) {
      cout << i << '\n';
      return;
    }
  }
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