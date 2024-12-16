#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  string S;
  cin >> N >> S;
  int a = count(S.begin(), S.end(), 'U');
  if (a & 1) cout << "YES\n";
  else cout << "NO\n";
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